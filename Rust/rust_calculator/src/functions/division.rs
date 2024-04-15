pub fn division(a: f64, b: f64) -> f64 {
    if b == 0.0 {
        panic!("Cannot divide by zero.");
    }
    a / b
}