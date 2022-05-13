import chisel3._
import chisel3.experimental.ChiselEnum
import chisel3.util._
import junctions._

class CacheReq(addrWidth:Int, dataWidth:Int) extends Bundle {
	val addr = UInt(addrWidth.W)
	val data = UInt(dataWidth.W)
	val mask = UInt((dataWidth/8).W)
}


class CacheResp(dataWidth:Int) extends Bundle {
	val data = UInt(dataWidth.W)
}

class CacheIO(addrWidth: Int, dataWidth: Int) extends Bundle {
	val abort = Input(Bool())
	val req   = Flipped(Valid(new CacheReq(addrWidth, dataWidth)))
	val resp  = Valid(new CacheResp(dataWidth))
}

class CacheModuleIO(nastiParams: NastiBundleParameters, addrWidth: Int, dataWidth: Int) extends Bundle {
	val cpu = new CacheIO(addrWidth, dataWidth)  // 这个接口是跟CPU进行数据交换
	val nasti = new NastiBundle(nastiParams)  //这个接口是跟MEM 进行数据交换
}