use std::io;
use std::env;

pub mod functions;
pub mod constants;

pub use functions::*;
pub use constants::*;

fn main() {
    // Read the operator from command line arguments
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        println!("Usage: {} <operator>", args[0]);
        return;
    }
    let operator = &args[1];

    println!("First number:");
    let mut num1 = String::new();
    io::stdin().read_line(&mut num1).expect("Error");
    let num1: f64 = num1.trim().parse().expect("Input not valid");

    println!("Second number:");
    let mut num2 = String::new();
    io::stdin().read_line(&mut num2).expect("Error");
    let num2: f64 = num2.trim().parse().expect("Input not valid.");

    // Perform operation
    let result = match operator.as_str() {
        "+" => sum(num1, num2),
        "-" => substractions(num1, num2),
        "*" => multiplication(num1, num2),
        "/" => division(num1, num2),
        _ => {
            println!("Invalid operator.");
            return;
        }
    };
    println!("The result of {} {} {} is: {}", num1, operator, num2, result);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sum() {
        assert_eq!(sum(5.0, 3.0), 8.0);
        assert_eq!(sum(-5.0, 3.0), -2.0);
        assert_eq!(sum(0.0, 0.0), 0.0);
    }

    #[test]
    fn test_substractions() {
        assert_eq!(substractions(5.0, 3.0), 2.0);
        assert_eq!(substractions(-5.0, 3.0), -8.0);
        assert_eq!(substractions(0.0, 0.0), 0.0);
    }

    #[test]
    fn test_multiplication() {
        assert_eq!(multiplication(5.0, 3.0), 15.0);
        assert_eq!(multiplication(-5.0, 3.0), -15.0);
        assert_eq!(multiplication(0.0, 5.0), 0.0);
    }

    #[test]
    fn test_division() {
        assert_eq!(division(6.0, 3.0), 2.0);
        assert_eq!(division(-6.0, 3.0), -2.0);
        assert_eq!(division(0.0, 5.0), 0.0);
    }

    #[test]
    #[should_panic(expected = "Cannot divide by zero.")]
    fn test_division_by_zero() {
        division(5.0, 0.0);
    }
}
