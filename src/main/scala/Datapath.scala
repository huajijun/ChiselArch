import chisel3._
import chisel3.util._

object Const {
	val PC_START = 0x200
	val PC_EVEC  = 0x100
}

class DatapathIO(xlen:Int) extends Bundle {
	val host   = new HostIO(xlen)
	val icache = Flipped(new CacheIO(xlen,xlen))
	val dcache = Flipped(new CacheIO(xlen,xlen))
	val ctrl   = Flipped(new ControlSignals)
}

class Datapath(val conf:CoreConfig) extends Module {
	val io 		= IO(new DatapathIO(conf.xlen))
	val csr 	= Module(new CSR(conf.xlen))
	val regFile = Module(new RegFile(conf.xlen))
	val alu     = Module(conf.makeAlu(conf.xlen))
	val immGen	= Module(conf.makeImmGen(conf.xlen))
	val brCond  = Module(conf.makeBrCond(conf.xlen))

	import Control._

	val fe_inst = RegInit(Instructions.NOP)
	val fe_pc   = Reg(UInt())

	val ew_inst = RegInit(Instructions.NOP)
	val ew_pc	= Reg(UInt())
	val ew_alu	= Reg(UInt())
	val csr_in 	= Reg(UInt())


	val st_type = Reg(io.ctrl.st_type.cloneType)
	val ld_type = Reg(io.ctrl.ld_type.cloneType)
	val wb_sel = Reg(io.ctrl.wb_sel.cloneType)
	val wb_en = Reg(Bool())
	val csr_cmd = Reg(io.ctrl.csr_cmd.cloneType)
	val illegal = Reg(Bool())
	val pc_check = Reg(Bool())

	val started = RegNext(reset.asBool)

	val stall = !io.icache.resp.valid || !io.dcache.resp.valid
	val pc = RegInit(Const.PC_START.U(conf.xlen.W) - 4.U(conf.xlen.W))
	val npc = Mux(
		stall,
		pc,
		Mux(
			csr.io.expt,
			csr.io.evec,
			Mux(
				io.ctrl.pc_sel === PC_EPC,
				csr.io.epc,
				Mux(
					io.ctrl.pc_sel === PC_ALU || brCond.io.taken,
					alu.io.sum >> 1.U << 1.U,
					Mux(io.ctrl.pc_sel == PC_0, pc, pc+4.U)
				)
			)
		)
	)

	val inst = 
		Mux(started || io.ctrl.inst_kill || brCond.io.taken || csr.io.expt, Instructions.NOP, io.icache.resp.bits.data)
	pc := npc
	io.icache.req.bits.addr := npc
	io.icache.req.bits.data := 0.U
	io.icache.req.bits.mask := 0.U
	io.icache.req.valid := !stall
	io.icache.abort := false.B


	when(!stall) {
		fe_pc := pc
		fe_inst := inst
	}

	io.ctrl.inst := fe_inst

	val rd_addr = fe_inst(11, 7)
	val rs1_addr = fe_inst(19, 15)
	val rs2_addr = fe_inst(24, 20)
	regFile.io.raddr1 := rs1_addr
	regFile.io.raddr2 := rs2_addr

	immGen.io.inst := fe_inst
	immGen.io.sel := io.ctrl.imm_sel


	val wb_rd_addr = ew_inst(11, 7)
	val rs1hazard = wb_en && rs1_addr.orR && (rs1_addr === wb_rd_addr)
	val rs2hazard = wb_en && rs2_addr.orR && (rs2_addr === wb_rd_addr)
	val rs1 = Mux(wb_sel === WB_ALU && rs1hazard, ew_alu, regFile.io.rdata1)
	val rs2 = Mux(wb_sel === WB_ALU && rs2hazard, ew_alu, regFile.io.rdata2)


	alu.io.A := Mux(io.ctrl.A_sel === A_RS1, rs1, fe_pc)
	alu.io.B := Mux(io.ctrl.B_sel === B_RS2, rs2, immGen.io.out)
	alu.io.alu_op := io.ctrl.alu_op


	brCond.io.rs1 := rs1
	brCond.io.rs2 := rs2
	brCond.io.br_type := io.ctrl.br_type

	val daddr = Mux(stall, ew_alu, alu.io.sum) >> 2.U << 2.U
	val woffset = (alu.io.sum(1) << 4.U).asUInt | (alu.io.sum(0) << 3.U).asUInt
	io.dcache.req.valid := !stall && (io.ctrl.st_type.orR || io.ctrl.ld_type.orR)
	io.dcache.req.bits.addr := daddr
	io.dcache.req.bits.data := rs2 << woffset
	io.dcache.req.bits.mask := MuxLookup(
		Mux(stall, st_type, io.ctrl.st_type),
		"b0000".U,
		Seq(ST_SW -> "b1111".U, ST_SH -> ("b11".U << alu.io.sum(1, 0)), ST_SB -> ("b1".U << alu.io.sum(1, 0)))
	)

	when(reset.asBool || !stall && csr.io.expt) {
		st_type := 0.U
		ld_type := 0.U
		wb_en := false.B
		csr_cmd := 0.U
		illegal := false.B
		pc_check := false.B
	}.elsewhen(!stall && !csr.io.expt) {
		ew_pc := fe_pc
		ew_inst := fe_inst
		ew_alu := alu.io.out
		csr_in := Mux(io.ctrl.imm_sel === IMM_Z, immGen.io.out, rs1)
		st_type := io.ctrl.st_type
		ld_type := io.ctrl.ld_type
		wb_sel := io.ctrl.wb_sel
		wb_en := io.ctrl.wb_en
		csr_cmd := io.ctrl.csr_cmd
		illegal := io.ctrl.illegal
		pc_check := io.ctrl.pc_sel === PC_ALU
	}

}