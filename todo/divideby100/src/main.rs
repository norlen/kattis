use std::io::{self, BufRead};

fn main() {
    let mut n = String::new();
    let mut m = String::new();
    io::stdin().lock().read_line(&mut n).unwrap();
    io::stdin().lock().read_line(&mut m).unwrap();

    let after_dec = m.len();
    let (before, after) = if after_dec <= n.len() {
        let i = n.len() - after_dec;
        (n[..i].to_owned(), n[i..].to_owned())
    } else {
        let zeroes = after_dec - n.len();
        let zeroes = (0..zeroes).map(|_i| '0').collect::<String>();
        ("0".to_owned(), zeroes + &n)
    };

    let before = if before.len() == 0 {
        "0".to_owned()
    } else {
        before
    };

    let after = after.trim();
    let after = after.trim_end_matches('0');

    let out = if after.len() == 0 {
        before
    } else {
        format!("{}.{}", before, after)
    };
    println!("{}", out);
}
