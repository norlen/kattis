use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let mut initials = String::new();
        initials.push(line.as_bytes()[0] as char);

        let line = &line[1..];
        for (i, ch) in line.chars().enumerate() {
            if ch == '-' {
                let letter = line.as_bytes()[i + 1] as char;
                initials.push(letter);
            }
        }
        println!("{}", initials);
    }
}
