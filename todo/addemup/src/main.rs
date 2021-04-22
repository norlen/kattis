use std::collections::HashMap;
use std::io::{self, BufRead};

fn main() {
    let mut data = String::new();
    io::stdin().lock().read_line(&mut data).unwrap();
    let data: Vec<_> = data.split(" ").collect();
    let n = data[0].trim().parse::<i64>().expect("1");
    let sum = data[1].trim().parse::<i64>().expect("2");

    let mut nums = vec![];
    let mut m = HashMap::new();
    for _ in 0..n {
        let mut s = String::new();
        io::stdin().lock().read_line(&mut s).expect("3");
        for c in s.split(" ") {
            if c.len() != 0 {
                let num = c.trim().parse::<i64>().unwrap();
                nums.push(num);
                m.insert(num, nums.len() - 1);
            }
        }
    }

    for (i, n) in nums.into_iter().enumerate() {
        let desired = sum - n;
        println!("desired: {}", desired);
        if m.contains_key(&desired) && i != *m.get(&desired).unwrap() {
            println!("YES");
            return;
        }
    }
    println!("NO");
}
