module Counter(
  input        clock,
  input        reset,
  input        io_inc,
  input  [3:0] io_amt,
  output [7:0] io_tot
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] REG; // @[Accum.scala 100:20]
  wire [7:0] _GEN_1 = {{4'd0}, io_amt}; // @[Accum.scala 101:35]
  wire [7:0] _T_1 = REG + _GEN_1; // @[Accum.scala 101:35]
  assign io_tot = REG; // @[Accum.scala 114:10]
  always @(posedge clock) begin
    if (reset) begin // @[Accum.scala 100:20]
      REG <= 8'h0; // @[Accum.scala 100:20]
    end else if (io_inc) begin // @[Accum.scala 101:15]
      REG <= _T_1; // @[Accum.scala 101:19]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  REG = _RAND_0[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
