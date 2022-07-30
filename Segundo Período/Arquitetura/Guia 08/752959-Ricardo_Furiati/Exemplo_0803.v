/*Exemplo_0803 
Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959
*/

// ------------------------- definir dados
module  Exemplo0803;
reg [3:0] a,b;
wire[3:0] bitwise;
wire logical;


xnor XNOR0 (bitwise[0],a[0],b[0]);
xnor XNOR1 (bitwise[1],a[1],b[1]);
xnor XNOR2 (bitwise[2],a[2],b[2]);
xnor XNOR3 (bitwise[3],a[3],b[3]);

and (logical,bitwise[0], bitwise[1],bitwise[2],bitwise[3]);


// ------------------------- parte principal
initial begin
$display("Exemplo0803 - Comparador Igualdade");

end
endmodule 