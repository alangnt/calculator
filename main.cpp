#include <iostream>
#include <limits>

constexpr float calculate(float a, float b, char operator_choice) noexcept
{
    switch (operator_choice)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

char select_operator()
{
    char operator_choice;

    while (true)
    {
        std::cout << "Enter operator (+, -, *, /): ";
        if (std::cin >> operator_choice && (operator_choice == '+' || operator_choice == '-' || operator_choice == '*' || operator_choice == '/'))
        {
            break;
        }

        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return operator_choice;
}

float select_second_number(char operator_choice)
{
    float number;

    while (true)
    {
        std::cout << "Enter second number: ";
        if (std::cin >> number && (operator_choice != '/' || number != 0))
        {
            break;
        }

        if (operator_choice == '/' && number == 0)
        {
            std::cout << "Cannot divide by zero. Try again.\n";
        }
        else
        {
            std::cout << "Invalid input. Try again.\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return number;
}

float select_first_number()
{
    float number;

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

        float first_number = select_first_number();
        char operator_choice = select_operator();
        float second_number = select_second_number(operator_choice);

        std::cout << "Result: " << calculate(first_number, second_number, operator_choice) << "\n"
                  << std::endl;

        if (!prompt_to_continue())
        {
            break;
        }
    }

    return 0;
}