use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let w = s.trim().parse::<i64>().unwrap();

    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let n = s.trim().parse::<i64>().unwrap();

    let mut area = 0;
    for _ in 0..n {
        let mut s = String::new();
        io::stdin().lock().read_line(&mut s).unwrap();
        let d: Vec<_> = s
            .split(" ")
            .map(|s| s.trim().parse::<i64>().unwrap())
            .collect();
        area += d[0] * d[1];
    }
    println!("{}", area / w);
}
