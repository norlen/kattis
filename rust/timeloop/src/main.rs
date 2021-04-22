use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let n = s.trim().parse::<i64>().unwrap();
    for i in 0..n {
        println!("{} Abracadabra", i + 1);
    }
}
