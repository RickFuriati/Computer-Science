/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
Guia_0101.v
*/
module Guia_0101;
// define data
integer a = 26; // decimal
integer b= 55; // Variáveis correspondem aos valores a serem convertidos em cada alternativa (encontram-se em decimal)
integer c= 713;
integer d= 312;
integer e= 366;
reg [7:0] x = 0; // binary
// actions
initial
begin : main
$display ( "Guia_01 - Exercicio 1 Conversao de decimal para binario" );
x=a;
$display ("Alternativa A) Decimal: %2d  Binario: %8b",a,x);
x=b;
$display ("Alternativa B) Decimal: %2d  Binario: %8b",b,x);
x=c;
$display ("Alternativa C) Decimal: %2d  Binario: %8b",c,x);
x=d;
$display ("Alternativa D) Decimal: %2d  Binario: %8b",d,x);
x=e;
$display ("Alternativa E) Decimal: %2d  Binario: %8b",e,x);

end // main
endmodule // Guia_0101

