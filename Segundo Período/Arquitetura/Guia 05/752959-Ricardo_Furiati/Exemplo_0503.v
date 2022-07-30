/*/*Nome: Ricardo Henrique Guedes Furiati
Matricula: 752959 */
/*
Guia_0502
*/
/*

   m a b s
   0 0 0 0
   1 0 1 1 <- a | ~b
   2 1 0 0
   3 1 1 0

*/

// estado dos elementos
module f5a (output s, input a, b);

   wire not_b;

   not NOT1 ( not_b, b );
   or OR1 ( s, not_b, a );

endmodule

// expressao
module f5b (output s, input a, b);

   assign s = (a | ~b);

endmodule

module test_f5;

   reg x;
   reg y;
   
   wire s;
   
   f5a moduloA ( s, x, y );
   f5b moduloB ( s, x, y );

   initial begin : main
      $display("--------- Guia0502 (a |~b) ---------\n");
      $display("  a |~b = s\n\n  a b  s");
      $monitor("  %b %b  %b ", x, y, s);

      x = 1'b0; y = 1'b0;
      #1 x = 1'b0; y = 1'b1;
      #1 x = 1'b1; y = 1'b0;
      #1 x = 1'b1; y = 1'b1;
   
   end

endmodule