use std::io::{self, Write};

// Try building programs to do the following:
// - Convert temperatures between Fahrenheit and Celsius.
// - Generate the nth Fibonacci number.
// - Print the lyrics to the Christmas carol “The Twelve Days of Christmas,” taking advantage of the repetition in the song. *
//
// * I really don't feel like it.

const DEFAULT_FAHRENHEIT: i32 = 63;
const DEFAULT_FIB_IDX: u8 = 100;
const MAX_FIB_IDX: u8 = 186;

fn main() {
    let fahrenheit = match get_input("enter degrees in fahrenheit")
        .trim()
        .parse::<i32>()
    {
        Ok(v) => v,
        Err(e) => {
            println!("invalid input: {}\n\nusing default value", e);
            DEFAULT_FAHRENHEIT
        }
    };

    println!("{fahrenheit}F = {}C", fahrenheit_to_celsius(fahrenheit));

    let fib_idx = match get_input("enter fibonacci index").trim().parse::<u8>() {
        Ok(v) => v.min(MAX_FIB_IDX),
        Err(e) => {
            println!("invalid input: {}\n\nusing default value", e);
            DEFAULT_FIB_IDX
        }
    };

    println!("{fib_idx}th fibonacci number = {}", fib(fib_idx));
}

fn get_input(prompt: &str) -> String {
    let mut input = String::new();
    print!("{prompt} > ");
    io::stdout().flush().expect("failed to flush stdout");
    io::stdin()
        .read_line(&mut input)
        .expect("failed to read line");

    input
}

fn fahrenheit_to_celsius(f: i32) -> i32 {
    (f - 32) * 5 / 9
}

fn fib(n: u8) -> u128 {
    if n <= 1 {
        return u128::from(n);
    }

    let mut c: (u128, u128) = (0, 1);
    for _ in 2..n {
        if c.0 < c.1 {
            c.0 += c.1;
            continue;
        }
        c.1 += c.0;
    }
    c.0 + c.1
}
