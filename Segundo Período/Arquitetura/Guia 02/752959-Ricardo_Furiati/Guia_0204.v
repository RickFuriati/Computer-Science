/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
/*
Guia_0204
*/
module Guia_0204;
// define data
real x = 0.625;// decimal
real i=0.0; // Variável para armazenar a parte inteira (base decimal)
reg [7:0] b = 8'b1010_0000 ; // binary
reg[15:0] bf; // Variáveç para manipular a parte fracionária em binário
integer b4[3:0];   //Variável para manipular a parte inteira na base 4
integer b4f[6:0]; //Variável para manipular a parte fracionária na base 4
reg[11:0] hex; //Variável para manipular a parte inteira em hexadecimal
reg[23:0] hexf; //Variável para manipular a parte fracionaria em hexadecimal
reg[8:0] oct;  //Variável para manipular a parte inteira em octal
reg[17:0] octf; //Variável para manipular a parte fracionaria em octal
// actions
initial 
begin : main
$display ( "Guia_02 - Exercicio 4 Conversao entre as  bases indicadas");

//A) 0,321 (4) para base 2
b4[3]=3; //atribuindo as posições
b4[2]=2;
b4[1]=1;
b4[0]=0;
b[7:6]=b4[3]; //atribuindo os valores às posições
b[5:4]=b4[2];
b[3:2]=b4[1];   
b[1:0]=b4[0];

$display ("Alternativa A) Base 4: 0.%1d%1d%1d%1d  Base 2: %2b%2b%2b%b ",b4[3],b4[2],b4[1],b4[0],b[7:6],b[5:4],b[3:2],b[1:0]);

//B) 0,3C7(16) para base 2
hex=12'h3C7; //Atribuindo o valor hexadecimal
b4[3]=hex[11:10]; //atribuindo os valores às posições
b4[2]=hex[9:8];
b4[1]=hex[7:6];
b4[0]=hex[5:4];

$display ("Alternativa B) Base 16: 0.%x  Base 4: 0.%2b%2b%2b%b ",hex,b4[3],b4[2],b4[1],b4[0]);

//C) 0,734 (8) para base 2
oct=9'o734; //Atribuindo o valor octal
b[7:5]=oct[8:6]; //atribuindo os valores às posições
b[4:2]=oct[5:3];
b[1:0]=oct[3:1];

$display ("Alternativa C) Base 8: 0.%o  Base 2: 0.%2b%2b%2b%b ",oct,b[7:5],b[4:2],b[1:0]);
 
//D)7,510 (8) para base 4 (Conversão de octal para binário e depois para base 4)
octf=18'o7_510; //Atribuindo o valor octal fracionario
bf[15:8]=octf[17:9];//atribuindo os valores às posições
bf[7:0]=octf[9:1]; //Parte inteira
b4f[6]=bf[15:13];
b4f[5]=bf[12:10];
b4f[4]=bf[9:8];
b4f[3]=bf[7:6]; //Parte fracionaria
b4f[2]=bf[5:4];
b4f[1]=bf[3:2];
b4f[0]=bf[1:0];

$display ("Alternativa D) Base 8: %o.%o  Base 4: %1d%1d%1d.%1d%1d%1d%1d ",octf[17:9],octf[8:0],b4f[6],b4f[5],b4f[4],b4f[3],b4f[2],b4f[1],b4f[0]);

//E) A,D91 (16) para base 4 (conversão por desagrupamento)
hexf=24'hA_D91;//Atribuindo o valor hexadecimal fracionario
b4f[6]=hexf[23:16];//atribuindo os valores às posições
b4f[5]=hexf[15:14];//Parte inteira
b4f[4]=hexf[13:12];
b4f[3]=hexf[11:10];//Parte fracionaria
b4f[2]=hexf[9:8];
b4f[1]=hexf[7:6];
b4f[0]=hexf[5:4];

$display ("Alternativa E) Base 16: %x.%x  Base 4: %1d%1d%1d.%1d%1d%1d%1d ",hexf[23:12],hexf[23:12],b4f[6],b4f[5],b4f[4],b4f[3],b4f[2],b4f[1],b4f[0]);

end // main
endmodule // Guia_0204