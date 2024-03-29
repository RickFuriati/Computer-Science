// -------------------------
// Exemplo_0902 
// Nome: Ricardo Henrique Guedes Furiati
// Matricula: 752959
// -------------------------
// ---------------------------
// -- test clock generator (2)
// ---------------------------
module clock ( output clk );
    reg clk;

    initial begin
        clk = 1'b0;
    end

    always begin
        #12 clk = ~clk;
    end
endmodule

module pulse ( signal, clock );
    input clock;
    output signal;
    reg signal;
    
    always @ ( clock ) begin
        signal = 1'b1;
        #3 signal = 1'b0;
        #3 signal = 1'b1;
        #3 signal = 1'b0;
    end

endmodule // pulse

module trigger ( signal, on, clock );
    input on, clock;
    output signal;
    reg signal;

    always @ ( posedge clock & on ) begin
        #60 signal = 1'b1;
        #60 signal = 1'b0;
    end
endmodule // trigger

module Exemplo_0902;

    wire clk;
    clock CLK1 (clk);

    reg p;
    wire p1, t1;

    pulse PULSE1 (p1, clk);

    trigger TRIGGER1 (t1, p, clk);


    initial begin
        p = 1'b0;
    end

    initial begin
        $dumpfile("Exemplo_0902.vcd");
        $dumpvars(1, clk, p1, p, t1);

        #060 p = 1'b1;
        #120 p = 1'b0;
        #180 p = 1'b1;
        #240 p = 1'b0;
        #300 p = 1'b1;
        #360 p = 1'b0;
        #376 $finish;
    end

endmodule


