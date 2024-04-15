#include <iostream>
#include <stdexcept>

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

int main() {
    std::cout << "Simple Calculator" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;

    int choice;
    std::cout << "Select operation (1/2/3/4): ";
    std::cin >> choice;

    double num1, num2;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    try {
        switch (choice) {
            case 1:
                std::cout << num1 << " + " << num2 << " = " << addition(num1, num2) << std::endl;
                break;
            case 2:
                std::cout << num1 << " - " << num2 << " = " << subtraction(num1, num2) << std::endl;
                break;
            case 3:
                std::cout << num1 << " * " << num2 << " = " << multiplication(num1, num2) << std::endl;
                break;
            case 4:
                std::cout << num1 << " / " << num2 << " = " << division(num1, num2) << std::endl;
                break;
            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
