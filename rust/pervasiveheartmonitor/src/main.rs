use std::io;
use std::io::BufRead;

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let n: Vec<&str> = line
            .split_whitespace()
            .collect();
        let mut beats = 0.0;
        let mut count = 0;
        let mut name = "".to_owned();
        for w in n {
            if w.as_bytes()[0] >= '0' as u8 && w.as_bytes()[0] <= '9' as u8 {
                beats += w.parse::<f64>().unwrap();
                count += 1;
            } else {
                if name.len() > 0 {
                    name.push(' ');
                }
                name += w;
            }
        }
        println!("{} {}", beats / count as f64, name);
    }
}
