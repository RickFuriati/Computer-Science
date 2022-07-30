/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
Guia_0302
*/
module Guia_0302;
// define data
reg [7:0] a = 8'h0a; // binary
reg [6:0] b = 8'o15 ; // binary
reg [5:0] c = 13 ; // binary
reg [7:0] d = 0; // binary
reg [6:0] e = 0; // binary
reg [5:0] f = 0; // binary
// actions
initial
begin : main
$display ( "Guia_03 - Exercicio 2 complementos Indicados" );
//A) C1,6 213 (4) 
c=39;
f=~c+1;
$display ( "Alternativa A) %6b -> Complemento de 1(c) = %6b -> C2(c) = %6b", c, ~c, f );

//B) C1,8 6D (16) 
a=8'h6d;
d=~a+1;
$display ( "Alternativa B) %8b -> Complemento de 1(a) = %8b -> C2(a) = %8b", a, ~a, d );

//C) C2,6 321 (4)
c=57;
f=~c+1;
$display ( "Alternativa C) %6b -> Complemento de 1(c) = %6b -> C2(c) = %8b", c, ~c, f );

//D) C2,7 175 (8) 
b = 8'o175;
e = ~b+1; 
$display ( "Alternativa D)  %7b -> Complemento de 1(b) = %7b -> C2(b) = %7b", b, ~b, e );

//E) C2,8 F4 (16) 
a= 8'hf4;
d=~a+1;
$display ( "Alternativa E) %8b -> Complemento de 1(a)= %8b -> C2(a) = %8b", a, ~a, d );

end // main
endmodule // Guia_0302