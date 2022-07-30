/*Nome: Ricardo Henrique Guedes Furiati
  Matricula: 752959 */
/*
Guia_0104.v
*/
module Guia_0104;
// define data
reg [7:0] x = 0;
reg [7:0] a = 5'b10011; // binary (bits)
reg [7:0] b = 5'b11101; // Variáveis correspondem aos valores a serem convertidos em cada alternativa (encontram-se em binário)
reg [7:0] c = 6'b101001;
reg [7:0] d = 6'b110101;
reg [7:0] e = 6'b111001;
// actions
initial
begin : main
$display ( "Guia_01 - Exercicio 4 Conversao de binario para base desejada "  ); 
$display ("Alternativa A) Binario: %5b  base 4: %2d" ,a,a);
$display ("Alternativa B) Binario: %5b  base octal(8): %0o" ,b,b);
$display ("Alternativa C) Binario: %6b  hexadecimal(16): %0x" ,c,c);
$display ("Alternativa D) Binario: %6b  base octal(8): %0o" ,d,d);
$display ("Alternativa E) Binario: %6b  base 4: %2d" ,e,e);

end // main
endmodule // Guia_0104