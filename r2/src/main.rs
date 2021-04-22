use std::io::{self, BufRead};

fn main() {
    let mut data = String::new();
    io::stdin().lock().read_line(&mut data).unwrap();
    let data: Vec<i64> = data
        .split(" ")
        .map(|s| s.trim().parse::<i64>().unwrap())
        .collect();

    // (r1 + r2) / 2 = s
    // 2s - r1 = r2
    let (r1, s) = (data[0], data[1]);
    let r2 = 2 * s - r1;

    println!("{}", r2);
}
