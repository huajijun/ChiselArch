
import chisel3._
import chisel3.iotesters.{PeekPokeTester, Driver, ChiselFlatSpec}
import chisel3.util._
import org.scalatest._


object Alu {
  val ALU_ADD = 0.U(4.W)
  val ALU_SUB = 1.U(4.W)
  val ALU_AND = 2.U(4.W)
  val ALU_OR = 3.U(4.W)
  val ALU_XOR = 4.U(4.W)
  val ALU_SLT = 5.U(4.W)
  val ALU_SLL = 6.U(4.W)
  val ALU_SLTU = 7.U(4.W)
  val ALU_SRL = 8.U(4.W)
  val ALU_SRA = 9.U(4.W)
  val ALU_COPY_A = 10.U(4.W)
  val ALU_COPY_B = 11.U(4.W)
  val ALU_XXX = 15.U(4.W)
}

class AluIO(width: Int) extends Bundle {
  val rs1 = Input(UInt(width.W))
  val rs2 = Input(UInt(width.W))
  val alu_op = Input(UInt(4.W))
  val out = Output(UInt(width.W))
  val sum = Output(UInt(width.W))
}

trait Alu extends Module {
	def width:Int
	val io:AluIO
}

import Alu._

class AluSimple(val width: Int) extends Alu {
	val io = IO(new AluIO(width))
	val shamt = io.rs2(4, 0).asUInt

	io.out := MuxLookup(
		io.alu_op,
		io.rs2,
		Seq(
			ALU_ADD -> (io.rs1 + io.rs2),
			ALU_SUB -> (io.rs1 - io.rs2),
			ALU_SRA -> (io.rs1 >> shamt),
			ALU_SRL -> (io.rs1 << shamt), 
			ALU_SLT -> (io.rs1.asSInt < io.rs2.asSInt),
			ALU_SLTU -> (io.rs1 < io.rs2),
			ALU_AND -> (io.rs1 & io.rs2),
			ALU_OR -> (io.rs1 | io.rs2),
			ALU_XOR -> (io.rs1 ^ io.rs2),
			ALU_COPY_A -> io.rs1
		)
	)

	io.sum := io.rs1 + Mux(io.alu_op(0), -io.rs2, io.rs2)
}

class AluTest(item: AluSimple) extends PeekPokeTester(item) {
	val maxValue = 1 << item.width
		for (i <- 0 until 100) {
			val rs1 = rnd.nextInt(maxValue)
			val rs2 = rnd.nextInt(maxValue)
			val alu_op = rnd.nextInt(12)
			poke(item.io.rs1,rs1)
			poke(item.io.rs2,rs2)
			poke(item.io.alu_op,alu_op)
			step(1)
		}
}


object AluTest extends App {
	chisel3.iotesters.Driver.execute(Array("--generate-vcd-output", "on", "--is-verbose","--backend-name","verilator"),() => new AluSimple(8)){
				c => new AluTest(c)	
	}
}
