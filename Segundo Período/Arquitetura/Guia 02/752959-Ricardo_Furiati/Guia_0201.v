/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
/*
Guia_0201
*/
module Guia_0201;
// define data
real
x = 0 ; // decimal
real power2 = 1.0; // power of 2
integer
y = 7 ; // counter
reg [7:0] b = 8'b10100000; // binary (only fraction part, Big Endian)
reg[7:0]f; //Variável utilizada para se efetuar a conversao da parte fracionaria quando a parte inteira é diferente de zero.
// actions
initial
begin : main
$display ( "Guia_02 - Exercicio 1 Conversao de binario para decimal" );


// A) 0,10101 (2) para base 10
b=8'b10101000;
x=0;
power2=1.0;
y=7;
while (y>= 0)
begin
    power2=power2/2.0;
    if(b[y]==1)
    begin
        x=x+power2;
    end
    y=y-1;
end//
$display ("Alternativa A) Binario: %8b  Decimal: %f" ,b,x);

// B) 0,01101(2) para base 10
b=8'b01101000;
x=0;
power2=1.0;
y=7;
while (y>= 0)
begin
    power2=power2/2.0;
    if(b[y]==1)
    begin
        x=x+power2;
    end
    y=y-1;
end//
$display ("Alternativa B) Binario: %8b  Decimal: %f" ,b,x);

// C) 0,11101(2) para base 10
b=8'b11101000;
x=0;
power2=1.0;
y=7;
while (y>= 0)
begin
    power2=power2/2.0;
    if(b[y]==1)
    begin
        x=x+power2;
    end
    y=y-1;
end//
$display ("Alternativa C) Binario: %8b  Decimal: %f" ,b,x);

// D) 1,10111(2) para base 10 
// A partir da alternativa D a parte inteira dos numeros passa a ser diferente de zero, levando a necessidade de se efetuar 2 conversoes (uma para parte inteira e outra para a parte fracionaria), a parte inteira corresponde a variável 'b' e a fracionaria a variáveç 'f'
b=8'b10111000;
x=0;
power2=1.0;
y=7;
f=b;
//Conversao da parte fracionaria (utilizando a variavel 'f')
while (y>= 0)
begin
    power2=power2/2.0;
    if(b[y]==1)
    begin
        x=x+power2;
    end
    y=y-1;
end//
//Conversao da parte inteira 
b=8'b00000001;
power2=1.0;
y=0;
while (y<= 7)
begin
    if(y==0)
    begin
        power2=1.0;
    end
    else
    begin
        power2=power2*2.0;
    end
    if(b[y]==1)
    begin
        x=x+power2;
    end 
    y=y+1;
end//
$display ("Alternativa D) Binario: %8b.%8b  Decimal: %f" ,b,f,x);

// E) 11,11110(2) para base 10
//Segue a mesma lógica da alternativa anterior (parte inteira é diferente de zero)
b=8'b11110000;
x=0;
power2=1.0;
y=7;
f=b;
//Conversao da parte fracionaria (utilizando a variavel 'f')

while (y>= 0)
begin
    power2=power2/2.0;
    if(b[y]==1)
    begin
        x=x+power2;
    end
    y=y-1;
end//
//Conversao da parte inteira
b=8'b00000011;
power2=1.0;
y=0;
while (y<= 7)
begin
    if(y==0)
    begin
        power2=1.0;
    end
    else
    begin
        power2=power2*2.0;
    end
    if(b[y]==1)
    begin
        x=x+power2;
    end 
    y=y+1;
end//
$display ("Alternativa E) Binario: %8b.%8b  Decimal: %f" ,b,f,x);

end // main
endmodule // Guia_0201