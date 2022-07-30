/*Exemplo_0804 
Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959
*/

// ------------------------- definir dados
module  Exemplo0804;
reg [3:0] a,b;
wire[3:0] bitwise;
wire logical;


xor XOR0 (bitwise[0],a[0],b[0]);
xor XOR1 (bitwise[1],a[1],b[1]);
xor XOR2 (bitwise[2],a[2],b[2]);
xor XOR3 (bitwise[3],a[3],b[3]);

or (logical,bitwise[0], bitwise[1],bitwise[2],bitwise[3]);


// ------------------------- parte principal
initial begin
$display("Exemplo0804 - Comparador Desigualdade");

end
endmodule 