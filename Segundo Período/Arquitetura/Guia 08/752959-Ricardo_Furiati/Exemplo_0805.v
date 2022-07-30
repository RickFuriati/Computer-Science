/*Exemplo_0805 - FULL ADDER
// Nome: Ricardo Henrique Guedes Furiati
// Matricula: 752959
// -------------------------
// -------------------------
// half adder
-------------------------*/
module halfAdder (output s0,carryOut,input a,input b);
// descrever por portas
xor XOR1 ( s0, a, b );
and AND1 (carryOut, a, b );
endmodule // halfAdder// -------------------------
// full adder
// -------------------------
module fullAdder ( output s1,carryOut,input a,input b,carryIn );
// descrever por portas e/ou modulos
wire out_adder1, cout_addr1, cout_adder2;
halfAdder Adder1 (out_adder1,cout_adder1,a,b);
halfAdder Adder2 (s,cout_adder2,cout_adder1,carryIn);
or OR1 (carry_out,cout_adder1,cout_adder2);
endmodule // fullAdder

// ------------------------- definir dados
module  Exemplo0805;
reg [3:0] a,b;
wire [3:0] not_a;
not notA[3:0] (not_a,a);
wire[4:0] s;
wire gnd, cout_fa1, cout_fa2, cout_fa3;
fullAdder FA1 (s[0], cout_fa1, a[0], b[0], 1'b0);
fullAdder FA2 (s[1], cout_fa2, a[1], b[1], cout_fa1);
fullAdder FA3 (s[2], cout_fa3, a[2], b[2], cout_fa2);
fullAdder FA4 (s[3], gnd, not_a[3],1'b0,cout_fa3);

// ------------------------- parte principal
initial begin
$display("Exemplo0805 - Complemento de 2");
// projetar testes do somador completo
end
endmodule // test_fullAdder