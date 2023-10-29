module a;
    real b,c;
    initial begin
        $fscanf(32'h8000_0000,"%d%d",b,c);
        $display("%.10f",b/c);
    end
endmodule