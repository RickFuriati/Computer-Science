/*Nome: Ricardo Henrique Guedes Furiati
  Matricula: 752959 */
/*
/*
Guia_0202
*/
module Guia_0202;
// define data
real x = 0.0; // decimal
integer y = 7 ; // counter
integer i = 0; // Variável para armazenar a parte inteira
reg [7:0] b = 0 ; // binary
// actions
initial
begin : main
$display ( "Guia_02 - Exercicio 2 Conversao de decimal para binario");

// A) 0,625000 (10) para base 2
x=0.62500;
y=7;
i=0;
b=0;
    while ( x > 0 && y >= 0 )
        begin
        if ( x*2 >= 1 )
            begin
            b[y] = 1;
            x = x*2.0 - 1.0;
            end
        else
            begin
            b[y] = 0;
            x = x*2.0;
        end // end if
    y =y-1; 
    end // end while
$display ("Alternativa A) Decimal: %2d.%2d  Binario: %b.%8b",i,x,i,b);

//B) 1,12500 (10) para base 2
x=0.12500;
y=7;
i=1;
b=0;
    while ( x > 0 && y >= 0 )
        begin
        if ( x*2 >= 1 )
            begin
            b[y] = 1;
            x = x*2.0 - 1.0;
            end
        else
            begin
            b[y] = 0;
            x = x*2.0;
        end // end if
    y =y-1; 
    end // end while
$display ("Alternativa B) Decimal: %d  Binario: %2b.%8b",x,i,b);

//C) 1,03125 (10) para base 2
x=0.03125;
y=7;
i=1;
b=0;
    while ( x > 0 && y >= 0 )
        begin
        if ( x*2 >= 1 )
            begin
            b[y] = 1;
            x = x*2.0 - 1.0;
            end
        else
            begin
            b[y] = 0;
            x = x*2.0;
        end // end if
    y =y-1; 
    end // end while
$display ("Alternativa C) Decimal: %d  Binario: %2b.%8b",x,i,b);

//D) 3,87500 (10) para base 2
x=0.87500;
y=7;
i=3;
b=0;
    while ( x > 0 && y >= 0 )
        begin
        if ( x*2 >= 1 )
            begin
            b[y] = 1;
            x = x*2.0 - 1.0;
            end
        else
            begin
            b[y] = 0;
            x = x*2.0;
        end // end if
    y =y-1; 
    end // end while
$display ("Alternativa D) Decimal: %d  Binario: %2b.%8b",x,i,b);

//E) 11,37500 (10) para base 2
x=0.37500;
y=7;
i=11;
b=0;
    while ( x > 0 && y >= 0 )
        begin
        if ( x*2 >= 1 )
            begin
            b[y] = 1;
            x = x*2.0 - 1.0;
            end
        else
            begin
            b[y] = 0;
            x = x*2.0;
        end // end if
    y =y-1; 
    end // end while
$display ("Alternativa E) Decimal: %d  Binario: %2b.%8b",x,i,b);













end // main
endmodule // Guia_0202