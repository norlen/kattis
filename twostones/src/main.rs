use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let n = s.trim().parse::<i64>().unwrap();
    if n % 2 == 0 {
        println!("Bob");
    } else {
        println!("Alice");
    }
}
