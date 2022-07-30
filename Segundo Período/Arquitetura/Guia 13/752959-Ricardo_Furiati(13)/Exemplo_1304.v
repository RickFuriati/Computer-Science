module Diff (output q, output qnot,
           input d,
           input clock, input clear, input preset);

reg q, qnot;

always @ ( posedge clock or clear or preset )
begin
    if (clear) begin q<=0; qnot<=1; end
    else
      if (preset) begin q<=1; qnot<=0; end
      else
        begin q<=d; qnot<=~d; end
end
endmodule

module JK (output q, output qnot,
           input j, input k,
           input clock, input clear, input preset);

reg q, qnot;

always @ (posedge clock or clear or preset)
begin
    if (clear) begin q<=0; qnot<=1; end
    else
      if (preset) begin q<=1; qnot<=0; end
      else
      if (j&~k) begin q<=1; qnot<=0; end
      else
        if (~j&k) begin q<=0; qnot<=1; end
        else
        if (j&k) begin q<=~q; qnot<=~qnot; end
end
endmodule

module Contador (output A, B, C, D,
                input clock, in, clear, preset);
wire gnd;
JK ffa(A, gnd, in, in, B, clear, preset);
JK ffb(B, gnd, in, in, C, clear, preset);
JK ffc(C, gnd, in, in, D, clear, preset);
JK ffe(D, gnd, in, in, clock, clear, preset);

endmodule

module main;

reg clock, clear, preset;
reg in;
wire[3:0] out;

Contador Exemplo4 ( out[3], out[2], out[1], out[0], clock, in, clear, preset);

initial
begin
$display(" Contador Asssíncrono Decrescente (4 bits)");
$display("A|B|C|D|Número");
clock    = 1;
in     = 0;
clear  = 1;
preset = 0;

    #1 clear = 0; #1 in = 1;

    #66 $finish;
end

always
#2 clock=~clock;

always @ (negedge clock)
begin
    $display(" %b %b %b %b %d", out[3], out[2], out[1], out[0], out);
end
endmodule