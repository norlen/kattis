use std::collections::HashMap;
use std::io::{self, BufRead};

fn print_fox_sound(map: &HashMap<String, bool>, s: &str) {
    let out = s
        .split(" ")
        .filter_map(|s| {
            if !map.contains_key(&s.trim().to_owned()) {
                Some(s.trim().to_owned())
            } else {
                None
            }
        })
        .collect::<Vec<String>>()
        .join(" ");
    println!("{}", out);
}

fn main() {
    let mut num_test_cases = String::new();
    io::stdin().lock().read_line(&mut num_test_cases).unwrap();

    for _ in 0..num_test_cases.trim().parse::<usize>().unwrap() {
        let mut test_case = String::new();
        io::stdin().lock().read_line(&mut test_case).unwrap();

        let mut sounds: HashMap<String, bool> = HashMap::new();
        loop {
            let mut s = String::new();
            io::stdin().lock().read_line(&mut s).unwrap();
            if s.starts_with("what does the fox say?") {
                print_fox_sound(&sounds, &test_case);
                break;
            }

            let ss = s.split("goes").skip(1).next().unwrap().trim().to_owned();
            sounds.insert(ss, true);
        }
    }
}
