use std::io::{self, BufRead};

fn main() {
    const THICKNESS: i64 = 4;

    let mut data = String::new();
    io::stdin().lock().read_line(&mut data).unwrap();
    let data: Vec<i64> = data
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let (n, v, h) = (data[0], data[1], data[2]);

    let area = [v * h, (n - v) * h, v * (n - h), (n - h) * (n - v)];
    let area = area.iter().copied().max().unwrap();
    println!("{}", area * THICKNESS);
}
