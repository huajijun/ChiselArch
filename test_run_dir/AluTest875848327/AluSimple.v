module AluSimple(
  input        clock,
  input        reset,
  input  [7:0] io_rs1,
  input  [7:0] io_rs2,
  input  [3:0] io_alu_op,
  output [7:0] io_out,
  output [7:0] io_sum
);
  wire [4:0] shamt = io_rs2[4:0]; // @[Alu.scala 41:27]
  wire [7:0] _T_1 = io_rs1 + io_rs2; // @[Alu.scala 47:44]
  wire [7:0] _T_3 = io_rs1 - io_rs2; // @[Alu.scala 48:44]
  wire [7:0] _T_4 = io_rs1 >> shamt; // @[Alu.scala 49:44]
  wire [38:0] _GEN_0 = {{31'd0}, io_rs1}; // @[Alu.scala 50:44]
  wire [38:0] _T_5 = _GEN_0 << shamt; // @[Alu.scala 50:44]
  wire  _T_8 = $signed(io_rs1) < $signed(io_rs2); // @[Alu.scala 51:51]
  wire  _T_9 = io_rs1 < io_rs2; // @[Alu.scala 52:45]
  wire [7:0] _T_10 = io_rs1 & io_rs2; // @[Alu.scala 53:44]
  wire [7:0] _T_11 = io_rs1 | io_rs2; // @[Alu.scala 54:43]
  wire [7:0] _T_12 = io_rs1 ^ io_rs2; // @[Alu.scala 55:44]
  wire [7:0] _T_14 = 4'h0 == io_alu_op ? _T_1 : io_rs2; // @[Mux.scala 80:57]
  wire [7:0] _T_16 = 4'h1 == io_alu_op ? _T_3 : _T_14; // @[Mux.scala 80:57]
  wire [7:0] _T_18 = 4'h9 == io_alu_op ? _T_4 : _T_16; // @[Mux.scala 80:57]
  wire [38:0] _T_20 = 4'h8 == io_alu_op ? _T_5 : {{31'd0}, _T_18}; // @[Mux.scala 80:57]
  wire [38:0] _T_22 = 4'h5 == io_alu_op ? {{38'd0}, _T_8} : _T_20; // @[Mux.scala 80:57]
  wire [38:0] _T_24 = 4'h7 == io_alu_op ? {{38'd0}, _T_9} : _T_22; // @[Mux.scala 80:57]
  wire [38:0] _T_26 = 4'h2 == io_alu_op ? {{31'd0}, _T_10} : _T_24; // @[Mux.scala 80:57]
  wire [38:0] _T_28 = 4'h3 == io_alu_op ? {{31'd0}, _T_11} : _T_26; // @[Mux.scala 80:57]
  wire [38:0] _T_30 = 4'h4 == io_alu_op ? {{31'd0}, _T_12} : _T_28; // @[Mux.scala 80:57]
  wire [38:0] _T_32 = 4'ha == io_alu_op ? {{31'd0}, io_rs1} : _T_30; // @[Mux.scala 80:57]
  wire [7:0] _T_35 = 8'h0 - io_rs2; // @[Alu.scala 60:46]
  wire [7:0] _T_36 = io_alu_op[0] ? _T_35 : io_rs2; // @[Alu.scala 60:31]
  assign io_out = _T_32[7:0]; // @[Alu.scala 43:16]
  assign io_sum = io_rs1 + _T_36; // @[Alu.scala 60:26]
endmodule
