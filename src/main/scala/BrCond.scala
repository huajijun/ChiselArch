import chisel3._
import Control._
import chisel3.iotesters.{PeekPokeTester, Driver, ChiselFlatSpec}
import chisel3.util._
import org.scalatest._
class BrCondIO(val xlen: Int) extends Bundle {
	val rs1 = Input(UInt(xlen.W))
	val rs2 = Input(UInt(xlen.W))
	val br_type = Input(UInt(3.W))
	val taken = Output(Bool())
}

trait BrCond extends Module {
	def xlen: Int
	val io: BrCondIO
}

class BrCondSimple(val xlen: Int) extends BrCond {
	val io = IO(new BrCondIO(xlen))
	val eq = io.rs1 === io.rs2
	val neq = !eq
	val lt = io.rs1.asSInt < io.rs2.asSInt
	val ge = !lt
	val ltu = io.rs1 < io.rs2
	val geu = !ltu

	io.taken :=
		((io.br_type === BR_EQ) && eq) ||
		((io.br_type === BR_NE) && neq) ||
		((io.br_type === BR_LT) && lt) ||
		((io.br_type === BR_GE) && ge) ||
		((io.br_type === BR_LTU) && ltu) ||
		((io.br_type === BR_GEU) && geu)
}

class BrCondTest(item:BrCondSimple) extends PeekPokeTester(item) {
	val maxValue = 1 << item.xlen
	val maxValueOfBr = 1 << 3
	for (i <- 0 until 100) {
		val rs1 = rnd.nextInt(maxValue)
		val rs2 = rnd.nextInt(maxValue)
		val br_type = rnd.nextInt(maxValueOfBr)
		poke(item.io.rs1,rs1)
		poke(item.io.rs2,rs2)
		poke(item.io.br_type,br_type)
		step(1)
	}
}

object BrCondTest extends App {
	chisel3.iotesters.Driver.execute(Array("--generate-vcd-output", "on", "--is-verbose","--backend-name",
		"verilator"),() => new BrCondSimple(8)){
				c => new BrCondTest(c)	
	}
}