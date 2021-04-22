use std::io::{self, BufRead};

fn main() {
    let mut n = String::new();
    io::stdin().lock().read_line(&mut n).unwrap();
    let n = n.trim().parse::<i64>().unwrap();

    let mut ans = 0;
    for _ in 0..n {
        let mut d = String::new();
        io::stdin().lock().read_line(&mut d).unwrap();
        let d = d.trim().parse::<i64>().unwrap();

        let num = d / 10;
        let exp = d % 10;
        ans += num.pow(exp as u32);
    }
    println!("{}", ans);
}
