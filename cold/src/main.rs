use std::io::{self, BufRead};

fn main() {
    let mut n = String::new();
    io::stdin().lock().read_line(&mut n).unwrap();

    let mut data = String::new();
    io::stdin().lock().read_line(&mut data).unwrap();

    let mut below_zero = 0;
    for s in data.split(" ") {
        if s.trim().parse::<i64>().unwrap() < 0 {
            below_zero += 1;
        }
    }

    println!("{}", below_zero);
}
