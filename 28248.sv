module boj28248;
    int p, c;
    int ans;
    initial begin
        $fscanf('h8000_0000, "%d%d", p, c);
        ans = p * 50 - c * 10;
        if (p > c)
            ans += 500;
        $display("%0d", ans);
    end
endmodule
