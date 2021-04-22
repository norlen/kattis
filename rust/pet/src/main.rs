use std::io::{self, BufRead};

fn main() {
    let mut n = 0;
    let mut sum = 0;
    for (i, line) in io::stdin()
        .lock()
        .lines()
        .map(|l| l.unwrap())
        .take(5)
        .enumerate()
    {
        let csum = line
            .split_whitespace()
            .map(|s| s.trim().parse::<i64>().unwrap())
            .fold(0, |a, c| a + c);
        if csum > sum {
            n = i + 1;
            sum = csum;
        }
    }
    println!("{} {}", n, sum);
}
