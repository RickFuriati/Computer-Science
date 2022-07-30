/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
Guia_0301
*/
module Guia_0301;
// define data
reg [7:0] a = 8'b000_1010 ; // binary
reg [6:0] b = 8'b000_101 ; // binary
reg [5:0] c = 8'b001_01 ; // binary
reg [7:0] d = 0; // binary
reg [6:0] e = 0; // binary
reg [5:0] f = 0; // binary
// actions
initial
begin : main
$display ( "Guia_03 - Exercicio 1 complementos Indicados" );
//A) C1,6 1011 (2) 
c=8'b1011;
f=~c+1;
$display ("Alternativa A)  %6b -> Complemento de 1(c) = %6b -> C2(c) = %8b", c, ~c, f );

//B) C1,8 1010 (2) 
a=8'b1010;
d=~a+1;
$display ( "Alternativa A)  %8b -> Complemento de 1(a) = %8b -> C2(a) = %8b", a, ~a, d );

//C) C2,6 110011 (2) 
c=8'b110011;
f=~c+1;
$display ( "Alternativa C) %6b -> Complemento de 1(c) = %6b -> C2(c) = %8b", c, ~c, f );

//D) C2,7 10111 (2)
b = 8'b10111;
e = ~b+1; 
$display ( "Alternativa D) %7b -> Complemento de 1(b) = %7b -> C2(b) = %7b", b, ~b, e );

//E) C2,8 110101 (2)
a= 8'b110101;
d=~a+1;
$display ( "Alternativa E) %8b -> Complemento de 1(a) = %8b -> C2(a) = %8b", a, ~a, e );

end // main
endmodule // Guia_0301