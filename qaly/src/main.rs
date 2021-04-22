use std::io::{self, BufRead};

fn main() {
    let mut n = String::new();
    io::stdin().lock().read_line(&mut n).unwrap();
    let n = n.trim().parse::<i64>().unwrap();

    let mut answer: f64 = 0.0;
    for _ in 0..n {
        let mut data = String::new();
        io::stdin().lock().read_line(&mut data).unwrap();
        let data: Vec<f64> = data
            .split(" ")
            .map(|s| s.trim().parse::<f64>().unwrap())
            .collect();

        answer += data[0] * data[1];
    }

    println!("{}", answer);
}
