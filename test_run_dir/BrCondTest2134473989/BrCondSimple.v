module BrCondSimple(
  input        clock,
  input        reset,
  input  [7:0] io_rs1,
  input  [7:0] io_rs2,
  input  [2:0] io_br_type,
  output       io_taken
);
  wire  eq = io_rs1 == io_rs2; // @[BrCond.scala 20:25]
  wire  neq = ~eq; // @[BrCond.scala 21:19]
  wire  lt = $signed(io_rs1) < $signed(io_rs2); // @[BrCond.scala 22:32]
  wire  ge = ~lt; // @[BrCond.scala 23:18]
  wire  ltu = io_rs1 < io_rs2; // @[BrCond.scala 24:26]
  wire  geu = ~ltu; // @[BrCond.scala 25:19]
  wire  _T_5 = io_br_type == 3'h6 & neq; // @[BrCond.scala 29:41]
  wire  _T_6 = io_br_type == 3'h3 & eq | _T_5; // @[BrCond.scala 28:48]
  wire  _T_8 = io_br_type == 3'h2 & lt; // @[BrCond.scala 30:41]
  wire  _T_9 = _T_6 | _T_8; // @[BrCond.scala 29:49]
  wire  _T_11 = io_br_type == 3'h5 & ge; // @[BrCond.scala 31:41]
  wire  _T_12 = _T_9 | _T_11; // @[BrCond.scala 30:48]
  wire  _T_14 = io_br_type == 3'h1 & ltu; // @[BrCond.scala 32:42]
  wire  _T_15 = _T_12 | _T_14; // @[BrCond.scala 31:48]
  wire  _T_17 = io_br_type == 3'h4 & geu; // @[BrCond.scala 33:42]
  assign io_taken = _T_15 | _T_17; // @[BrCond.scala 32:50]
endmodule
