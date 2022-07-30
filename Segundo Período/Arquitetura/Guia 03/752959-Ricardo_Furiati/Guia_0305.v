/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
Guia_0305
*/
module Guia_0305;
// define data
reg [2:0] a = 0 ; // binary
reg [3:0] b = 0 ; // binary
reg [4:0] c = 0 ; // binary
reg [4:0] d = 0; // binary
reg [6:0] e = 0; // binary


// actions
initial
begin : main
$display ( "Guia_03 - Exercicio 5 executar operacoes" );
//A) 101100 (2) – 1101 (2)
c=8'b101100 - 8'b1101;
$display ( "Alternativa A)  %b = %d",c,c);

//B) 101,1010 (2) – 2,3 (8)
c=8'b101_1010 - 8'b10_011;
$display ( "Alternativa B)   %b = %d",c,c);

//C) 231 (4) – F (16)
c=8'b101101 - 8'b1111;
$display ( "Alternativa C)   %b = %d",c,c);

//D) DC (16 ) – 1001011 (2)
c=8'b11011100 - 8'b1001011;
$display ( "Alternativa D) %b = %d",c,c);

//E) 36 (10) – 2B (16) 
c=8'b100100 - 8'b101011;
$display ( "Alternativa E)  %b = %d",c,c);

end // main
endmodule // Guia_0305