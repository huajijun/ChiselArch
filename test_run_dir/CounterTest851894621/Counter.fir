circuit Counter :
  module Counter :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip inc : UInt<1>, flip amt : UInt<4>, tot : UInt<8>}

    reg REG : UInt<8>, clock with :
      reset => (reset, UInt<8>("h0")) @[Accum.scala 100:20]
    when io.inc : @[Accum.scala 101:15]
      node _T = add(REG, io.amt) @[Accum.scala 101:35]
      node _T_1 = tail(_T, 1) @[Accum.scala 101:35]
      node _T_2 = gt(_T_1, UInt<8>("hff")) @[Accum.scala 97:11]
      node _T_3 = mux(_T_2, UInt<1>("h0"), _T_1) @[Accum.scala 97:8]
      REG <= _T_3 @[Accum.scala 101:19]
    io.tot <= REG @[Accum.scala 114:10]

