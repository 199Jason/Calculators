def addition(a, b):
    return a + b

def subtraction(a, b):
    return a - b

def multiplication(a, b):
    return a * b

def division(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b

def main():
    print("Simple Calculator")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")

    choice = input("Select operation (1/2/3/4): ")

    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))

    if choice == '1':
        print(f"{num1} + {num2} = {addition(num1, num2)}")
    elif choice == '2':
        print(f"{num1} - {num2} = {subtraction(num1, num2)}")
    elif choice == '3':
        print(f"{num1} * {num2} = {multiplication(num1, num2)}")
    elif choice == '4':
        try:
            print(f"{num1} / {num2} = {division(num1, num2)}")
        except ValueError as e:
            print(e)
   
