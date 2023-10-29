module boj28352;
    int arr[8];
    int key;
    initial begin
        arr[0] = 6;
        for(int i = 1; i < 8; i++) begin
            arr[i] = arr[i-1] * (i + 10);
        end
        $fscanf('h8000_0000, "%d", key);
        $display("%0d", arr[key-10]);
    end
endmodule
