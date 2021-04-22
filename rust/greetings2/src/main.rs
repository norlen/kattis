use std::io::{self, BufRead};

fn main() {
    let mut s = String::new();
    io::stdin().lock().read_line(&mut s).unwrap();
    let num_es = s.chars().filter(|c| *c == 'e').count();
    let mut es = String::new();
    for _ in 0..num_es * 2 {
        es.push('e');
    }
    println!("h{}y", es);
}
