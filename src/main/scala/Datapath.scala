import chisel3._
import chisel3.util._


class DatapathIO(xlen:Int) extends Bundle {
	val host   = new HostIO(xlen)
	val icache = Flipped(new CacheIO(xlen,xlen))
	val dcache = Flipped(new CacheIO(xlen,xlen))
	val ctrl   = Flipped(new ControlSignals)
}
