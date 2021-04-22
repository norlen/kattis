use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let lines: Vec<_> = stdin.lock().lines().map(|l| l.unwrap()).collect();
    let a = lines[0].parse::<i64>().unwrap();
    let b = lines[1].parse::<i64>().unwrap();

    let q = if a > 0 { [1, 4] } else { [2, 3] };
    let q = if b > 0 { q[0] } else { q[1] };

    println!("{}", q);
}
