circuit Accum :
  module Accum :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip in : UInt<1>, out : UInt<8>}

    reg reg : UInt<8>, clock with :
      reset => (reset, UInt<8>("h0")) @[Accum.scala 12:26]
    when io.in : @[Accum.scala 14:21]
      node _T = add(reg, UInt<1>("h1")) @[Accum.scala 15:27]
      node _T_1 = tail(_T, 1) @[Accum.scala 15:27]
      reg <= _T_1 @[Accum.scala 15:20]
    io.out <= reg @[Accum.scala 18:16]

