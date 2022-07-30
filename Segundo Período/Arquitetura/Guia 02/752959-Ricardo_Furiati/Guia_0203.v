/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
/*
Guia_0203
*/
module Guia_0203;
// define data
real
x = 0.0;
// decimal
reg [7:0] b = 8'b0000_0000 ; // binary
// actions
initial
begin : main
$display ( "Guia_02 - Exercicio 3 Conversao de binario para base indicada");

//A) 0,011101 (2) para base 4
b=8'b00_01_11_01; //Agrupamentos feitos de 2 em 3 (base 2 para base 4)
$display ("Alternativa A) Binario: %8b  base 4: %d.%d%d%d",b,b[7:6],b[5:4],b[3:2],b[1:0]);

//B) 0,100101 (2) para base 8
x=0.0;
b=8'b1001_0100; //Agrupamentos feitos de 3 em 3 (base 2 para base 8)
$display ("Alternativa B) Binario: %8b  base 8: %d.%o%o",b,x,b[7:5],b[4:2]);

//C)0,100110(2) para base 16
b=8'b00_100110; 
$display ("Alternativa C) Binario: %8b  base 8: %x.%x",b,b[7:6],b[5:0]);

//D)1,110011 (2) para base 8
x=1.0; //parte inteira
b=8'b1100_1100; //Agrupamentos feitos de 3 em 3 (base 2 para base 8)
$display ("Alternativa D) Binario: %8b  base 8: %d.%o%o",b,x,b[7:5],b[4:2]);

//E)1101,1101(2) para base 16

b=8'b1101_1101; 
$display ("Alternativa E) Binario: %8b  base 8: %x.%x",b,b[7:4],b[3:0]);

end // main
endmodule // Guia_0203