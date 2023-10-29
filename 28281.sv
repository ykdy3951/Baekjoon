module boj28281;
    int n, x, ans = 3000;
    int arr[100005];
    
    initial begin
        $fscanf('h8000_0000, "%d%d", n, x);
        $fscanf('h8000_0000, "%d", arr[0]);
        for(int i = 1; i < n; i++) begin
            arr[i] = 0;
            $fscanf('h8000_0000, "%d", arr[i]);
            if (ans > arr[i] + arr[i-1])
                ans = arr[i] + arr[i-1];
        end
        $display("%0d", ans*x);
    end
endmodule