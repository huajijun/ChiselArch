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

class Tile(val coreParam: CoreConfig, val nastiParams:NastiBundleParameters, val cacheParams:CacheConfig) extends Module {
	val io = IO(new TileIO(coreParam.xlen, nastiParams))
	val core = Module(new Core(coreParam))
	val icache = Module(new Cache(cacheParams,nastiParams, coreParam.xlen))
	val dcache = Module(new Cache(cacheParams,nastiParams, coreParam.xlen))
	val arb	   = Module(new MemArbiter(nastiParams))

	io.host <> core.io.host
	// 这里是不同级别的端口
	core.io.icache <> icache.io.cpu // 这里需要端口明是不同的输入和输出
	core.io.dcache <> dcache.io.cpu
	arb.io.icache <> icache.io.nasti
	arb.io.dcache <> dcache.io.nasti
	//
	io.nasti <> arb.io.nasti
}

