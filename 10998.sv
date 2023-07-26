module multiply;
    integer a,b;
    initial begin
        $fscanf(32'h8000_0000, "%d%d", a, b);
        $display("%0d", a*b);
    end
endmodule