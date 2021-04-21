use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let n = s.trim().parse::<i64>().unwrap();

    let mut rows = 2;
    for _ in 0..n {
        rows += rows - 1;
    }

    println!("{}", rows * rows);
}
