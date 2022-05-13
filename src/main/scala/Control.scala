import chisel3._
object Control {
	// br_type
	val BR_XXX = 0.U(3.W)
	val BR_LTU = 1.U(3.W)
	val BR_LT = 2.U(3.W)
	val BR_EQ = 3.U(3.W)
	val BR_GEU = 4.U(3.W)
	val BR_GE = 5.U(3.W)
	val BR_NE = 6.U(3.W)

	// index
	val IMM_X = 0.U(3.W)
	val IMM_I = 1.U(3.W)
	val IMM_S = 2.U(3.W)
	val IMM_U = 3.U(3.W)
	val IMM_J = 4.U(3.W)
	val IMM_B = 5.U(3.W)
	val IMM_Z = 6.U(3.W)
}

class ControlSignals extends Bundle {
	val inst = Input(UInt(32.W))
	val pc_sel = Output(UInt(2.W))
	val inst_kill = Output(Bool())
	val A_sel = Output(UInt(1.W))
	val B_sel = Output(UInt(1.W))
	val imm_sel = Output(UInt(3.W))
	val alu_op = Output(UInt(4.W))
	val br_type = Output(UInt(3.W))
	val st_type = Output(UInt(2.W))
	val ld_type = Output(UInt(3.W))
	val wb_sel = Output(UInt(2.W))
	val wb_en = Output(Bool())
	val csr_cmd = Output(UInt(3.W))
	val illegal = Output(Bool())
}

class Control extends Module {
	val io = IO(new ControlSignals)
}