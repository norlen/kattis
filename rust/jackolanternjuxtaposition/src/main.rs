use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();

    let s: Vec<_> = s
        .split(" ")
        .map(|s| s.trim().parse::<i64>().unwrap())
        .collect();
    println!("{}", s[0] * s[1] * s[2]);
}
