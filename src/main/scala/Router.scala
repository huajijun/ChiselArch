/* */

import chisel3._
import chisel3.util.{DeqIO, EnqIO, log2Ceil}

object Router {
	val addressWidth    = 32
	val dataWidth       = 64
	val headerWidth     =  8
	val routeTableSize  = 15
	val numberOfOutputs =  4
}

class ReadCmd extends Bundle {
	val addr = UInt(Router.addressWidth.W)
}

class WriteCmd extends Bundle {
	val data = UInt(Router.addressWidth.W)
}

class Packet extends Bundle {
	val header = UInt(Router.headerWidth.W)
	val body = UInt(Router.dataWidth.W)
}

class RouterIO(val n:Int) extends Bundle {
	val read_routing_table_request 	= DeqIO(new ReadCmd()) // 数据 输入端 bit = input , valid = input 这里表示输入的数据有效
	val read_routing_table_response = EnqIO(UInt(Router.addressWidthW)) // 数据 输入端 bit = output ,valid = output
	val load_routing_table_request 	= DeqIO(new WriteCmd())  // 数据输入端 bit = input , valid = input
	val in 							= DeqIO(new Packet())   // 数据输入端 bit = input , valid = input
	val outs 						= Vec(n, EnqIO(new Packet()))	 // 数据输出端 bit = input , valid = input
} 


class Router extends Module {
	val depth: Int 	= Router.routeTableSize
	val n: Int 		= Router.numberOfOutputs
	val io 			= IO(new RouterIO(n))
	val tbl 		= Mem(depth ,UInt(BigInt(n).bitLength.W))

	io.read_routing_table_request.nodeq() 
	// ready = false;  output
	io.load_routing_table_request.nodeq()
	// ready = false; output
	io.read_routing_table_response.noenq()
	// valid = false; output
	io.read_routing_table_response.bits := 0.U
	io.in.noenq()
	// valid = false; output
	io.outs.foreach {	out => 
		out.bits := 0.U.asTypeOf(out.bits)
		out.noenq()
		// valid = false; output
	}

	when(io.read_routing_table_request.valid && io.read_routing_table_response.ready) {
		io.read_routing_table_response.enq(tbl(
			// valid = true; bit = data
			io.read_routing_table_response.enq(tbl(
				// valid = true; bit = data
				io.read_routing_table_response.deq().addr
				// ready = true; bit
			))
		))
	}
	.elsewhen(io.load_routing_table_request.valid) {
		val cmd = io.load_routing_table_request.dep()
		tbl(cmd.addr) := cmd.data
	}
	.elsewhen(io.in.valid) {
		val pkt = io.in.bits
		val idx = tbl(pkt.header(log2Ceil(Router.routeTableSize), 0))
		when(io.outs(idx).ready) {
			io.in.dep()
			io.outs(idx).enq(pkt)
		}
	}
}