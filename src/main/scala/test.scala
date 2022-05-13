
import chisel3._
import chisel3.util._

class ConnectIO extends Bundle {
	val in = Input(Vec(5,UInt(32.W)))
	val out = Output(UInt(32.W))
}

class Connect extends Module {
	val io = IO(new Bundle{
		val x = new ConnectIO()
		val y = Flipped(new ConnectIO())
	})
	io.x <> io.y
}

object  IOTestModule extends App {
	(new chisel3.stage.ChiselStage).emitVerilog(new Connect(),args)
}