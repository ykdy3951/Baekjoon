module boj28290;
    string key, value;
    initial begin
        $fscanf('h8000_0000, "%s", key);
        
        if (key == "fdsajkl;" || key == "jkl;fdsa")
            value = "in-out";
        else if (key == "asdf;lkj" || key == ";lkjasdf")
            value = "out-in";
        else if (key == "asdfjkl;")
            value = "stairs";
        else if (key == ";lkjfdsa")
            value = "reverse";
        else 
            value = "molu";
        $display("%s", value);
    end
endmodule
