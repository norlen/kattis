use std::io::{self, BufRead};

fn main() {
    let mut n = String::new();
    io::stdin().lock().read_line(&mut n).unwrap();
    let n = n.trim().parse::<i64>().unwrap();
    if n % 2 == 1 {
        println!("still running");
    } else {
        let mut count = 0;
        for _ in 0..(n / 2) {
            let mut start = String::new();
            io::stdin().lock().read_line(&mut start).unwrap();

            let mut stop = String::new();
            io::stdin().lock().read_line(&mut stop).unwrap();
            let start = start.trim().parse::<i64>().unwrap();
            let stop = stop.trim().parse::<i64>().unwrap();
            count += stop - start;
        }
        println!("{}", count);
    }
}
