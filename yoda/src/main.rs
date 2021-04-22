use std::io::{self, BufRead};

fn main() {
    let nums: Vec<String> = io::stdin()
        .lock()
        .lines()
        .map(|l| l.unwrap())
        .take(2)
        .collect();

    // Fix strings with zero left padding.
    let max_len = if nums[0].len() > nums[1].len() {
        nums[0].len()
    } else {
        nums[1].len()
    };

    let s0: String = std::iter::repeat('0')
        .take(max_len - nums[0].len())
        .collect::<String>()
        + &nums[0];
    let s1: String = std::iter::repeat('0')
        .take(max_len - nums[1].len())
        .collect::<String>()
        + &nums[1];

    // collision.
    let mut a0 = String::new();
    let mut a1 = String::new();
    for (c0, c1) in s0.chars().zip(s1.chars()) {
        let n0 = c0.to_digit(10).unwrap();
        let n1 = c1.to_digit(10).unwrap();
        if n0 == n1 {
            a0.push(c0);
            a1.push(c1);
        } else if n0 > n1 {
            a0.push(c0);
        } else {
            a1.push(c1);
        }
    }

    // output
    if a0.len() == 0 {
        println!("YODA");
    } else {
        println!("{}", a0.parse::<i64>().unwrap());
    }
    if a1.len() == 0 {
        println!("YODA");
    } else {
        println!("{}", a1.parse::<i64>().unwrap());
    }
}
