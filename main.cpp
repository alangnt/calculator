#include <iostream>
#include <limits>
#include <stdexcept>

enum class Operator : char {
  Add = '+',
  Subtract = '-',
  Multiply = '*',
  Divide = '/'
};

double calculate(double a, double b, Operator operation) {
  switch (operation) {
  case Operator::Add:
    return a + b;
  case Operator::Subtract:
    return a - b;
  case Operator::Multiply:
    return a * b;
  case Operator::Divide:
    return a / b;
  default:
    throw std::invalid_argument("Invalid operator");
  }
}

Operator select_operator() {
  char input;

  while (true) {
    std::cout << "Enter operator (+, -, *, /): ";

    if (std::cin >> input &&
        (input == '+' || input == '-' || input == '*' || input == '/')) {
      return static_cast<Operator>(input);
    }

    std::cout << "Invalid input. Try again.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

double select_second_number(Operator operation) {
  double number;

  while (true) {
    std::cout << "Enter second number: ";

    if (!(std::cin >> number)) {
      std::cout << "Invalid input. Try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if (operation == Operator::Divide && number == 0) {
      std::cout << "Cannot divide by zero. Try again.\n";
      continue;
    }

    return number;
  }
}

double select_first_number() {
  double number;

  std::cout << "Enter first number: ";
  while (!(std::cin >> number)) {
    std::cout << "Invalid input. Please enter a valid number: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return number;
}

bool prompt_to_continue() {
  char continue_choice;

  while (true) {
    std::cout << "Do you wish to continue (y/n)? ";
    if (std::cin >> continue_choice &&
        (continue_choice == 'y' || continue_choice == 'n')) {
      break;
    }

    std::cout << "Invalid input. Please enter 'y' or 'n' (Yes/No): ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return continue_choice == 'y';
}

int main() {
  std::cout << "====================\n";
  std::cout << "Simple Calculator 🧮\n";
  std::cout << "====================\n";

  while (true) {

    const double first_number = select_first_number();
    const Operator operation = select_operator();
    const double second_number = select_second_number(operation);

    std::cout << "Result: " << calculate(first_number, second_number, operation)
              << "\n\n";

    if (!prompt_to_continue()) {
      break;
    }
  }

  return 0;
}