module boj28295;
    int t, dir = 0, loop = 10;
    string s = "NESW";

    initial begin
        while(loop--) begin
            $fscanf('h8000_0000, "%d", t);
            dir = (dir + t) % 4;
        end
        $display("%c", s[dir]);
    end
endmodule
