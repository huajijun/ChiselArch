circuit BrCondSimple :
  module BrCondSimple :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip rs1 : UInt<8>, flip rs2 : UInt<8>, flip br_type : UInt<3>, taken : UInt<1>}

    node eq = eq(io.rs1, io.rs2) @[BrCond.scala 20:25]
    node neq = eq(eq, UInt<1>("h0")) @[BrCond.scala 21:19]
    node _T = asSInt(io.rs1) @[BrCond.scala 22:25]
    node _T_1 = asSInt(io.rs2) @[BrCond.scala 22:41]
    node lt = lt(_T, _T_1) @[BrCond.scala 22:32]
    node ge = eq(lt, UInt<1>("h0")) @[BrCond.scala 23:18]
    node ltu = lt(io.rs1, io.rs2) @[BrCond.scala 24:26]
    node geu = eq(ltu, UInt<1>("h0")) @[BrCond.scala 25:19]
    node _T_2 = eq(io.br_type, UInt<3>("h3")) @[BrCond.scala 28:30]
    node _T_3 = and(_T_2, eq) @[BrCond.scala 28:41]
    node _T_4 = eq(io.br_type, UInt<3>("h6")) @[BrCond.scala 29:30]
    node _T_5 = and(_T_4, neq) @[BrCond.scala 29:41]
    node _T_6 = or(_T_3, _T_5) @[BrCond.scala 28:48]
    node _T_7 = eq(io.br_type, UInt<3>("h2")) @[BrCond.scala 30:30]
    node _T_8 = and(_T_7, lt) @[BrCond.scala 30:41]
    node _T_9 = or(_T_6, _T_8) @[BrCond.scala 29:49]
    node _T_10 = eq(io.br_type, UInt<3>("h5")) @[BrCond.scala 31:30]
    node _T_11 = and(_T_10, ge) @[BrCond.scala 31:41]
    node _T_12 = or(_T_9, _T_11) @[BrCond.scala 30:48]
    node _T_13 = eq(io.br_type, UInt<3>("h1")) @[BrCond.scala 32:30]
    node _T_14 = and(_T_13, ltu) @[BrCond.scala 32:42]
    node _T_15 = or(_T_12, _T_14) @[BrCond.scala 31:48]
    node _T_16 = eq(io.br_type, UInt<3>("h4")) @[BrCond.scala 33:30]
    node _T_17 = and(_T_16, geu) @[BrCond.scala 33:42]
    node _T_18 = or(_T_15, _T_17) @[BrCond.scala 32:50]
    io.taken <= _T_18 @[BrCond.scala 27:18]

