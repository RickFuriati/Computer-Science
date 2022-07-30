module tipoT (output q, output qnot,
           input t,
           input clock, input clear, input preset);

reg q, qnot;

always @ ( posedge clock or clear or preset )
begin
    if (clear) begin q<=0; qnot<=1; end
    else
      if (preset) begin q<=1; qnot<=0; end
      else
        if (t) begin q<=~q; qnot<=~qnot; end
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

module Contador (output A, B, C, D, E,
                input clock, in, clear, preset);
wire gnd, clear01;
reg reset=0;
assign clear01= clear|reset;
tipoT ffa(A, gnd, in, ~B, clear01, preset);
tipoT ffb(B, gnd, in, ~C, clear01, preset);
tipoT ffc(C, gnd, in, ~D, clear01, preset);
tipoT ffd(D, gnd, in, ~E, clear01, preset);
tipoT ffe(E, gnd, in, clock, clear01, preset);

always @ (clock) begin
    if(~A & B & ~C & ~D & E) begin reset=1; #1 reset=0; end
end 
endmodule

module main;

reg clock, clear, preset;
reg in;
wire[4:0] out;

Contador Exemplo5 (out[4], out[3], out[2], out[1], out[0], clock, in, clear, preset);

initial
begin
$display(" FlipFlop tipo T (5 bits)");
$display("A|B|C|D|E|Número");
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
    $display(" %b %b %b %b %b %d", out[4], out[3], out[2], out[1], out[0], out);
end
endmodule