/*Nome: Ricardo Henrique Guedes Furiati
  Matricula: 752959 */
/*
Guia_0103.v
*/
module Guia_0103;
// define data
integer a = 73; // decimal
integer b=47;  // Variáveis correspondem aos valores a serem convertidos em cada alternativa (encontram-se em decimal)
integer c=61; 
integer d=157; 
integer e=751; 
reg [7:0] x = 0; // binary
// actions
initial
begin : main
//A conversão para base 4 não foi efetuada tendo em vista que o verilog não a reconhece automaticamente 
$display ( "Guia_01 - Exercicio 3 Conversao de decimal para base desejada "  ); 
$display ("Alternativa A) Decimal: %2d  base 4: %2d" ,a,a);
$display ("Alternativa B) Decimal: %2d  base octal(8): %0o" ,b,b);
$display ("Alternativa C) Decimal: %2d  base hexadecimal(16): %0x" ,c,c);
$display ("Alternativa D) Decimal: %2d  base hexadecimal(16): %0x" ,d,d);
$display ("Alternativa E) Decimal: %2d  base hexadecimal(16): %0x" ,e,e);
end // main
endmodule // Guia_0103