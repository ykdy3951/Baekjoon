module a;
    integer b,c,d;
    initial begin
        d=$fscanf(32'h8000_0000, "%d%d", b,c);
        $display("%0d", b+c);
    end
endmodule