/*Nome: Ricardo Henrique Guedes Furiati
  Matricula: 752959 */
/*
Guia_0105.v
*/
module Guia_0105;
// define data
reg [7:0] x; // binary
reg [0:8][7:0] a = "PUC-Minas"; // 3 characters (8 bits)
reg [0:5][7:0] b ="2022-1";
reg [0:13][7:0] c ="Belo Horizonte";
// As alternativas D e E requerem que cada agrupamento de algarismos seja associado a uma variável independente tendo em vista que cada numero corresponde a um caracter e agrupa-los impossbilitaria a identificação do caracter
reg[0:7] d1 = 8'o124;
reg[0:7] d2 = 8'o141;
reg[0:7] d3 = 8'o162;
reg[0:7] d4 = 8'o144;
reg[0:7] d5 = 8'o145;

reg[0:7] e1= 8'h42;
reg[0:7] e2= 8'h2E;
reg[0:7] e3= 8'h48;
reg[0:7] e4= 8'h74;
reg[0:7] e5= 8'h65;
reg[0:7] e6= 8'h2E;
// actions
initial
begin : main
$display ( "Guia_01 - Exercicio 5 Conversao de strings para tabela ASCII "  );
$display ( "Alternativa A) String: %s  ASCII(hexadecimal - 16): %x %x %x %x %x %x %x %x %x",a, a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
$display ( "Alternativa B) String: %s  ASCII(hexadecimal - 16): %x %x %x %x %x %x",b, b[0],b[1],b[2],b[3],b[4],b[5]);
$display ( "Alternativa C) String: %s  ASCII(binario - 2): %b %b %b %b %b %b %b %b %b %b %b %b %b %b",c,c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],c[9],c[10],c[11],c[12],c[13]);
$display ( "Alternativa D) string: %o %o %o %o %o  ASCII: %s %s %s %s %s",d1,d2,d3,d4,d5,d1,d2,d3,d4,d5);
$display ( "Alternativa E) string: %x %x %x %x %x  ASCII: %s %s %s %s %s",e1,e2,e3,e4,e5,e1,e2,e3,e4,e5);
end // main
endmodule // Guia_0105