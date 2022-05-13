import chisel3._
import chisel3.experimental.ChiselEnum
import chisel3.util._


class TileIO(xlen: Int, nastiParams: NastiBundleParameters) extends Bundle {
	val host = new HostIO(xlen)
	val nasti = new NastiBundle(nastiParams)
}

object Tile {
	def apply(config: Config): Tile = new Tile(config.core, config.nasti, config.cache)
}