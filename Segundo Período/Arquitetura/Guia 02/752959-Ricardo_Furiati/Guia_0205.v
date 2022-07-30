/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
/*
Guia_0205
*/
module Guia_0205;
// define data
reg [7:0] a = 8'b0000_0000 ; // binary
reg [7:0] b = 8'b0000_0000 ; // binary
reg [7:0] c; //Variável utilizada para armazenar o resultado da operação 
// actions
initial
begin : main

$display ( "Guia_02 - Exercicio 5 fazer as operações indicadas");

//A) 101,01 (2) + 11,011 (2)
a=8'b0101_0100;
b=8'b0011_0110;
c=a+b;
$display ("Alternativa A) Operacao:%8b + %8b  Resultado: %b.%b",a,b,c[7:4],c[3:0]);

//B)1001,111 (2) - 10,11
a=8'b1001_1110;
b=8'b0010_1100;
c=a-b;
$display ("Alternativa B) Operacao:%8b - %8b  Resultado: %b.%b",a,b,c[7:4],c[3:0]);

//C) 100,011 (2) * 11,01 (2)
a=8'b0100_0110;
b=8'b0011_0100;
c=a*b;
$display ("Alternativa C) Operacao:%8b * %8b  Resultado: %b.%b",a,b,c[5:2],c[6:3]);

//D) 10110,01 (2) / 10,101 (2)
a=8'b10110_010;
b=8'b0010_1010;
c=a/b;
$display ("Alternativa D) Operacao:%8b / %8b  Resultado: %b.%b",a,b,c[5:2],c[6:3]);

//E) 1101001 (2) % 1001(2)
a=8'b01101001;
b=8'b00001001;
c=a%b;
$display ("Alternativa E) Operacao:%8b resto da divisao %8b  Resultado: %b",a,b,c);

end // main
endmodule // Guia_0205