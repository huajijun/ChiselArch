import chisel3._
import chisel3.iotesters.{PeekPokeTester, Driver, ChiselFlatSpec}
import chisel3.util._
import org.scalatest._

class Accum extends Module {
	val io = IO(new Bundle{
		val in = Input(Bool())
		val out = Output(UInt(8.W))
	})

	val reg = RegInit(0.U(8.W))

	when(io.in) {
		reg:= reg + 1.U
	}

	io.out := reg
}
object  AccumGen extends App {
	(new chisel3.stage.ChiselStage).emitVerilog(new Accum,args)
}

class AccumTest(item:Accum) extends PeekPokeTester(item) {
	var reg = 0
	for (i <- 0 until 300) {
		val in = rnd.nextInt(2)
		poke(item.io.in, in == 1)
		if (in == 1){
			reg = reg + 1
		}
		step(1)
		expect(item.io.out, reg)
	}
}

object AccumTest extends App {
	chisel3.iotesters.Driver.execute(Array("--generate-vcd-output", "on", "--is-verbose","--backend-name","verilator"),() => new Accum()){
			c => new AccumTest(c)
	}
}

class AdderS(var n:Int) extends Module {
	val io = IO(new Bundle{
		val a = Input(UInt(n.W))
		val b = Input(UInt(n.W))
		val out = Output(UInt(n.W))

	})
	io.out := io.a + io.b
}

class AdderTest(t:AdderS) extends PeekPokeTester(t) {
	val maxValue = 1 << t.n
	for(i <- 0 until 100) {
		val a = rnd.nextInt(maxValue)
		val b = rnd.nextInt(maxValue)
		val res = (a + b) & (maxValue - 1)
		poke(t.io.a,a)
		poke(t.io.b,b)
		step(1)
		expect(t.io.out,res)
	}
}
object AdderTest extends App {
	chisel3.iotesters.Driver.execute(Array("--generate-vcd-output", "on", "--is-verbose","--backend-name","verilator"),() => new AdderS(8)){
			c => new AdderTest(c)
	}
}

/*
object Counter {
	def Limit(max:UInt,number:UInt):UInt ={
		Mux(number > max, 0.U, number)
		//println(Mux(number > max, 0.U, number).asUInt)
	}
	def counter(maxValue:UInt, en:Bool, number:UInt):UInt ={
		val x = RegInit(0.U(maxValue.getWidth.W))
		when(en) {
			x := Limit(maxValue,x + number)
		}
		x
	}
}
class Counter extends Module {
	val io = IO(new Bundle{
		val inc = Input(Bool())
		val amt = Input(UInt(4.W))
		val tot = Output(UInt(8.W))
	})
	io.tot := Counter.counter(255.U,io.inc,io.amt)
}
*/
object Counter {

  def wrapAround(n: UInt, max: UInt) = 
    Mux(n > max, 0.U, n)

  def counter(max: UInt, en: Bool, amt: UInt): UInt = {
    val x = RegInit(0.U(max.getWidth.W))
    when (en) { x := wrapAround(x + amt, max) }
    x
  }

}

class Counter extends Module {
  val io = IO(new Bundle {
    val inc = Input(Bool())
    val amt = Input(UInt(4.W))
    val tot = Output(UInt(8.W))
  })

  io.tot := Counter.counter(255.U, io.inc, io.amt)

}
/*
class CounterTest(t:Counter) extends PeekPokeTester(t) {
	val maxValue = 1 << 4
	var res = 0
	for (i <- 0 until 200) {
		val en = rnd.nextInt(2)
		val rs = rnd.nextInt(maxValue)
		if (en == 1) {
			if (res + rs < 255) {
				res += rs
			} else {
				res = 0
			}
		}
		poke(t.io.inc,en == 1)
		poke(t.io.amt,rs)
		step(1)
		expect(t.io.tot,res)
	}
}
*/
class CounterTest(c: Counter) extends PeekPokeTester(c) {
  val maxInt  = 16
  var curCnt  = 0

  def intWrapAround(n: Int, max: Int) = 
    if(n > max) 0 else n

  poke(c.io.inc, 0)
  poke(c.io.amt, 0)

  // let it spin for a bit
  for (i <- 0 until 5) {
    step(1)
  }

  for (i <- 0 until 200) {
    val inc = rnd.nextBoolean()
    val amt = rnd.nextInt(maxInt)
    poke(c.io.inc, if (inc) 1 else 0)
    poke(c.io.amt, amt)
    step(1)
    curCnt = if(inc) intWrapAround(curCnt + amt, 255) else curCnt
    expect(c.io.tot, curCnt)
  }
}
object CounterTest extends App {
	chisel3.iotesters.Driver.execute(Array("--generate-vcd-output", "on", "--is-verbose","--backend-name","verilator"),() => new Counter()){
			c => new CounterTest(c)
	}
}
