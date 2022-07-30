// -------------------------
// Exemplo_0905 
// Nome: Ricardo Henrique Guedes Furiati
// Matricula: 752959
// -------------------------
// test clock generator (5)

`include "clock.v"

module pulse1 (signal, clock);
input clock;
output signal;
reg signal;

always @ (clock)
begin

    signal = 1'b1;
 #3 signal = 1'b0;


end
endmodule // pulse



module Exemplo_0905;
wire clock;
clock clk (clock);

wire p1;

pulse1 pls1 (p1, clock);

initial 
begin
    $dumpfile("Exemplo_0905.vcd");
    $dumpvars(1, clock, p1);

    #480 $finish;
end
endmodule //Exemplo_0903