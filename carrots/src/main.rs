use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let n: Vec<_> = s.split(" ").collect();
    let n1 = n[0].trim().parse::<i64>().unwrap();
    let s = n[1].trim().parse::<i64>().unwrap();
    for _ in 0..n1 {
        let mut _s = String::new();
        io::stdin().lock().read_line(&mut _s).unwrap();
    }
    println!("{}", s);
}
