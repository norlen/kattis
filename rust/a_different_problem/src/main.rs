use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let nums: Vec<_> = line
            .split_whitespace()
            .map(|num| num.parse::<i64>().unwrap())
            .collect();
        println!("{}", (nums[0] - nums[1]).abs());
    }
}
