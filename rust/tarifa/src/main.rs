use std::io::{self, BufRead};

fn main() {
    let mut x = String::new();
    io::stdin().lock().read_line(&mut x).unwrap();

    let mut n = String::new();
    io::stdin().lock().read_line(&mut n).unwrap();

    let n = n.trim().parse::<i64>().unwrap();
    let mut total = x.trim().parse::<i64>().unwrap() * (n + 1);

    for _ in 0..n {
        let mut s = String::new();
        io::stdin().lock().read_line(&mut s).unwrap();
        total -= s.trim().parse::<i64>().unwrap();
    }
    println!("{}", total);
}
