#include <iostream>
#include <limits>
#include <stdexcept>

enum class Operator
{
    Add,
    Subtract,
    Multiply,
    Divide
};

double calculate(double a, double b, Operator operator_choice)
{
    switch (operator_choice)
    {
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

Operator select_operator()
{
    char operator_choice;

    while (true)
    {
        std::cout << "Enter operator (+, -, *, /): ";

        if (std::cin >> operator_choice)
        {
            switch (operator_choice)
            {
            case '+':
                return Operator::Add;
            case '-':
                return Operator::Subtract;
            case '*':
                return Operator::Multiply;
            case '/':
                return Operator::Divide;
            }
        }

        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double select_second_number(Operator operator_choice)
{
    double number;

    while (true)
    {
        std::cout << "Enter second number: ";

        if (!(std::cin >> number))
        {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (operator_choice == Operator::Divide && number == 0)
        {
            std::cout << "Cannot divide by zero. Try again.\n";
            continue;
        }

        return number;
    }

    return number;
}

double select_first_number()
{
    double number;

    std::cout << "Enter first number: ";
    while (!(std::cin >> number))
    {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return number;
}

bool prompt_to_continue()
{
    char continue_choice;

    while (true)
    {
        std::cout << "Do you wish to continue (y/n)? ";
        if (std::cin >> continue_choice && (continue_choice == 'y' || continue_choice == 'n'))
        {
            break;
        }

        std::cout << "Invalid input. Please enter 'y' or 'n' (Yes/No): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return continue_choice == 'y';
}

int main()
{
    std::cout << "====================" << std::endl;
    std::cout << "Simple Calculator 🧮" << std::endl;
    std::cout << "====================" << std::endl;

    while (true)
    {

        double first_number = select_first_number();
        Operator operator_choice = select_operator();
        double second_number = select_second_number(operator_choice);

        std::cout << "Result: " << calculate(first_number, second_number, operator_choice) << "\n"
                  << std::endl;

        if (!prompt_to_continue())
        {
            break;
        }
    }

    return 0;
}