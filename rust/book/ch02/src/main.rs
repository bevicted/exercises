use rand::Rng;
use std::cmp::Ordering;
use std::io::{self, Write};

fn main() {
    let mut guess_count = 0;
    let number: u8 = rand::rng().random_range(1..=100);
    let mut guess = String::new();

    println!("I thought of a number between 1 and 100.\nGuess the number!");

    loop {
        guess.clear();

        print!("> ");
        io::stdout().flush().expect("flush failed");
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess = match guess.trim().parse::<u8>() {
            Ok(v) => v,
            Err(e) => {
                println!("\"{guess}\" is not a valid number... {e}");
                continue;
            }
        };

        guess_count += 1;

        match guess.cmp(&number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!\nAnd it only took you {guess_count} guesses! :tada:");
                break;
            }
        };
    }
}
