module boj28249;
    int ans = 0;
    initial begin
        int n;
        $fscanf('h8000_0000, "%d", n);
        for (int i = 0; i < n; i++) begin
            string s;
            $fscanf('h8000_0000, "%s", s);
            if (s == "Poblano") 
                ans += 3;
            else if (s == "Mirasol")
                ans += 12;
            else if (s == "Serrano")
                ans += 31;
            else if (s == "Cayenne")
                ans += 80;
            else if (s == "Thai")
                ans += 150;
            else
                ans += 250;
        end
        $display("%0d", ans*500);
    end
endmodule
