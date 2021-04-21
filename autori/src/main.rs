use std::io::{self, BufRead};

fn main() {
    for line in io::stdin().lock().lines().map(|l| l.unwrap()) {
        let initials: String = line.split('-').map(|s| s.as_bytes()[0] as char).collect();
        println!("{}", initials);
    }
}
