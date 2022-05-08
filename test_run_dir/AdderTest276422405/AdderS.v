module AdderS(
  input        clock,
  input        reset,
  input  [7:0] io_a,
  input  [7:0] io_b,
  output [7:0] io_out
);
  assign io_out = io_a + io_b; // @[Accum.scala 50:24]
endmodule
