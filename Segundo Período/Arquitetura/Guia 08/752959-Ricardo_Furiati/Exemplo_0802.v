/*Exemplo_0802
Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959
*/
// half subtractor
module halfSub (output s0,borrowIn,input a,input b);
// descrever por portas
wire not_a;
not NOT1(not_a,a);
xor XOR1 ( s0, a, b );
and AND1 (borrowIn, not_a, b );
endmodule 

module fullAdder ( output s1,borrows,input a,input b,borrowed );
// descrever por portas e/ou modulos
wire out_sub1, bout_sub1, bout_sub2;
halfSub Sub1 (out_sub1, bout_sub1, a, b);
halfSub Sub2 (s,bout_sub2, out_sub1,borrowed);
or OR1 (borrows,bout_sub1,bout_sub2);
endmodule 

// ------------------------- definir dados
module  Exemplo0802;
reg [3:0] a,b;
wire[4:0] s;
wire bout_fs1,bout_fs2,bout_fs3;
fullAdder FS1 (s[0], bout_fs1, a[0], b[0], 1'b0);
fullAdder FS2 (s[1], bout_fs2, a[1], b[1], bout_fs1);
fullAdder FS3 (s[2], bout_fs3, a[2], b[2], bout_fs2);
fullAdder FS4 (s[3], s[4], a[3], b[3], bout_fs3);

// ------------------------- parte principal
initial begin
$display("Exemplo0802 - Subtrator Completo");

end
endmodule // test_fullAdder