use std::io::{self, BufRead};

fn main() {
    let mut n = String::new();
    let mut m = String::new();
    io::stdin().lock().read_line(&mut n).unwrap();
    io::stdin().lock().read_line(&mut m).unwrap();

    let i = n.len() - m.len();
    let mut nn = n[..i].to_owned();
    if i != n.len() {
        nn.push('.');
        nn.push_str(&n[i..]);
    }

    let nn = nn.trim_end();
    let nn = nn.trim_end_matches('0');
    let mut nn = nn.trim_end_matches('.').to_owned();

    // Fix .d to 0.d
    if nn.as_bytes()[0] == '.' as u8 {
        let mut n = "0".to_owned();
        n.push_str(nn.as_str());
        nn = n;
    }
    println!("{}", nn);
}
