use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let n = s.trim().parse::<i64>().unwrap();

    for _ in 0..n {
        let mut s = String::new();
        io::stdin().lock().read_line(&mut s).unwrap();

        if s.starts_with("Simon says") {
            println!("{}", s.trim_start_matches("Simon says ").trim());
        }
    }
}
