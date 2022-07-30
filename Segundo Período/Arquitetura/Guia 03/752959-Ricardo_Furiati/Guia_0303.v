/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
Guia_0303
*/
module Guia_0303;
// define data
reg [7:0] a = 8'b1111_1010 ; // binary
reg [6:0] b = 8'b1111_101 ; // binary
reg [5:0] c = 8'b1111_10 ; // binary
reg [7:0] d = 0; // binary
reg [6:0] e = 0; // binary

// actions
initial
begin : main
$display ( "Guia_03 - Exercicio 3 determinar positivos equivalentes" );
//A) 1 0101 (2)
a=8'b10101;
d=~a+1;
e= ~(a-1);
$display ( "Alternativa A) %b -> Complemento de 1(a) = %b -> C2(a) = %b = %b= %d", a, ~a, d, d, e );

//B) 1 10111 (2)
a=8'b110111;
d=~a+1;
e= ~(a-1);
$display ( "Alternativa B) %b -> Complemento de 1(a) = %b -> C2(a) = %b = %b= %d", a, ~a, d, d, e );

//C) 1 10010 (2)
a=8'b110010;
d=~a+1;
e= ~(a-1);
$display ( "Alternativa C) %b -> Complemento de 1(a) = %b -> C2(a) = %b = %b= %d", a, ~a, d, d, e );

//D) 1 011101 (2)
a=8'b1011101;
d=~a+1;
e= ~(a-1);
$display ( "Alternativa D) %b -> Complemento de 1(a) = %b -> C2(a) = %b = %b= %d", a, ~a, d, d, e );

//E) 1 0110101 (2)
c=8'b10110101;
d=~c+1;
e= ~(c-1);
$display ( "Alternativa E) %6b -> Complemento de 1(c)= %6b -> C2(c) = %6b = %b= %x", c, ~c, d, d, e );
end // main
endmodule // Guia_0303