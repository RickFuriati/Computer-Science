/*Nome: Ricardo Henrique Guedes Furiati
  Matricula: 752959 */
/*
Guia_0102.v
*/
module Guia_0102;
// define data
integer x = 0;
// decimal
reg [7:0] a = 5'b10101; // binary (bits)
reg [7:0] b = 5'b11001; // Variáveis correspondem aos valores a serem convertidos em cada alternativa (encontram-se em binário)
reg [7:0] c = 6'b101001;
reg [7:0] d = 6'b101101;
reg [7:0] e = 6'b100011;
// actions
initial
begin : main
$display ( "Guia_01 - Exercicio 2 Conversao de binario para decimal "  );
x=a; 
$display ("Alternativa A) Binario: %5b  Decimal: %2d" ,a,x);
x=b;
$display ("Alternativa B) Binario: %5b  Decimal: %2d" ,b,x);
x=c;
$display ("Alternativa C) Binario: %6b  Decimal: %2d" ,c,x);
x=d;
$display ("Alternativa D) Binario: %6b  Decimal: %2d" ,d,x);
x=e;
$display ("Alternativa E) Binario: %6b  Decimal: %2d" ,e,x);

end // main
endmodule // Guia_0102