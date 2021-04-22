use std::io::{self, BufRead};

fn main() {
    let mut data = String::new();
    io::stdin().lock().read_line(&mut data).unwrap();
    let n = data.trim().parse::<i64>().unwrap();

    let distance = |l0: (usize, usize), l1: (usize, usize)| {
        let dx = (l0.0 as i64 - l1.0 as i64).abs();
        let dy = (l0.1 as i64 - l1.1 as i64).abs();
        f64::sqrt((dx * dx) as f64 + (dy * dy) as f64).ceil() as usize
    };

    for _ in 0..n {
        let mut data = String::new();
        io::stdin().lock().read_line(&mut data).unwrap();
        let info: Vec<usize> = data
            .split_whitespace()
            .map(|s| s.trim().parse::<usize>().unwrap())
            .collect();
        let width = info[0];

        let mut locations = vec![];
        for line in io::stdin().lock().lines().take(info[1]).map(|l| l.unwrap()) {
            let d: Vec<usize> = line
                .split_whitespace()
                .map(|s| s.trim().parse::<usize>().unwrap())
                .collect();
            locations.push((d[0], d[1]));
        }

        // All possible points we have available.
        let mut possible = vec![];
        for x in 1..(width - 1) {
            for y in 1..(width - 1) {
                if locations.contains(&(x, y)) {
                    continue;
                }
                // max distance before dog walks off
                let max_dist = usize::min(x, y);
                let max_dist = i64::min(
                    i64::min(width as i64 - x as i64, width as i64 - y as i64),
                    max_dist as i64,
                );

                let mut ok = true;
                for l in locations.iter().copied() {
                    if distance(l, (x, y)) > max_dist as usize {
                        ok = false;
                        break;
                    }
                }
                if ok {
                    possible.push((x, y));
                    break;
                }
            }
        }

        if possible.len() == 0 {
            println!("poodle");
        } else {
            println!("{} {}", possible[0].0, possible[0].1);
        }
    }
}
