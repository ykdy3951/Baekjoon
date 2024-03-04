use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap().to_string();

    let mut input_str = input.trim().to_string();
    let len = input_str.len();

    if (input_str.chars().nth(0) == Some('"')) && (input_str.chars().nth(len-1) == Some('"')) && (len > 2) {
        input_str.remove(len-1);
        input_str.remove(0);
        println!("{}", input_str);
    } else {
        println!("CE");
    }
}
