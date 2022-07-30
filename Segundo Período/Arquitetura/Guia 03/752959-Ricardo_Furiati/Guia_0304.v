/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
Guia_0304
*/
module Guia_0304;
// define data
reg [7:0] a = 8'b1111_1010 ; // binary
reg [6:0] b = 8'b1111_101 ; // binary
reg [5:0] c = 8'b1111_10 ; // binary
reg [7:0] d = 0; // binary
reg [6:0] e = 0; // binary
reg [5:0] f = 0; // binary

// actions
initial
begin : main
$display ( "Guia_03 - Exercicio 4 fazer as operacoes indicadas" );
//A) 11100 (2) - 1101 (2)
a=8'b11100;
b=8'b1101;
d=a-b;
$display ( "Alternativa A) a-b -> %b - %b =  %b -> %b", a, b, d, d);

//B) 101,1001 (2) - 10,01 (2)
a=8'b101_1001;
b=8'b10_01;
d=a-b;
$display ( "Alternativa D)  a-b -> %b - %b =  %b -> %b", a, b, d, d);

//C) 213 (4) - 123 (4)
a=8'b100111;
b=8'b11011;
d=a-b;
$display ( "Alternativa C)  a-b -> %b - %b -> %b ", a, b, d);

//D) 312 (8) - 123 (8)
a=8'o312;
b=8'o123;
d=a-b;
$display ( "Alternativa D)  a-b -> %b - %b -> %b = %o", a, b, d, d);

//E) 9D1 (16) - A1B (16)
a=16'h9d1;
b=16'ha1b;
d= a-b;
$display ( "Alternativa E) a-b ->  %b - %b -> %b = %x", a, b, d, d);
end // main
endmodule // Guia_0304