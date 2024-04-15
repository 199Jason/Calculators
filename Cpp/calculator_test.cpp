#include <iostream>
#include <cmath>

double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return a / b;
}

void runTests() {
    // Test addition
    if (addition(2, 3) != 5) {
        std::cout << "Addition test failed: expected 5, got " << addition(2, 3) << std::endl;
    }

    // Test subtraction
    if (subtraction(5, 3) != 2) {
        std::cout << "Subtraction test failed: expected 2, got " << subtraction(5, 3) << std::endl;
    }

    // Test multiplication
    if (multiplication(2, 3) != 6) {
        std::cout << "Multiplication test failed: expected 6, got " << multiplication(2, 3) << std::endl;
    }

    // Test division
    if (division(6, 3) != 2) {
        std::cout << "Division test failed: expected 2, got " << division(6, 3) << std::endl;
    }

    // Test division by zero
    try {
        division(5, 0);
        std::cout << "Division by zero test failed: did not throw exception" << std::endl;
    } catch (const std::invalid_argument& e) {
        // Test passed
    }
}

int main() {
    std::cout << "Running tests..." << std::endl;
    runTests();
    std::cout << "Tests completed." << std::endl;

    return 0;
}
