circuit AdderS :
  module AdderS :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip a : UInt<8>, flip b : UInt<8>, out : UInt<8>}

    node _T = add(io.a, io.b) @[Accum.scala 50:24]
    node _T_1 = tail(_T, 1) @[Accum.scala 50:24]
    io.out <= _T_1 @[Accum.scala 50:16]

