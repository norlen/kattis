use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let s: Vec<_> = s
        .split(" ")
        .map(|s| s.trim().parse::<i64>().unwrap())
        .collect();
    let (num_matches, w, h) = (s[0], s[1], s[2]);
    let max_len = f32::sqrt(w as f32 * w as f32 + h as f32 * h as f32) as i64;

    for _ in 0..num_matches {
        let mut s = String::new();
        io::stdin().lock().read_line(&mut s).unwrap();
        let n = s.trim().parse::<i64>().unwrap();
        if n <= max_len {
            println!("DA");
        } else {
            println!("NE");
        }
    }
}
