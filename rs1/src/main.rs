use std::env;
use bigint_base10::BigInteger;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() == 1 {
        println!("please pass cli args");
        println!("also make them i128 since I don't know how to error handle in rust");
        return;
    }

    let n: i128 = args[1].parse().unwrap();

    let mut i = BigInteger::new("1");
    let mut j =BigInteger::new("1");

    if args.len() == 4 {
        j = BigInteger::new(&args[2]);
        i = BigInteger::new(&args[3]);
    }

    for k in 0..n {
        println!("Iteration {}: [Max: {}, Min: {} ]", k, i, j);
        // let t: i128 = i;
        // i;
        // j = t;
    }
}
