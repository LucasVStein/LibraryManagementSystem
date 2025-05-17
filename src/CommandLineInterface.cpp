#include "CommandLineInterface.hpp"

CommandLineInterface &CommandLineInterface::getInstance()
{
    static CommandLineInterface instance;
    return instance;
}

void CommandLineInterface::startMenu() const {
    std::cout << "==============================\n";
    std::cout << "  Library Management System\n";
    std::cout << "==============================\n\n";

    std::cout << "1. Add a new book (TODO)\n";
    std::cout << "2. List all books (TODO)\n";
    std::cout << "3. Search for a book (TODO)\n";
    std::cout << "4. Borrow a book (TODO)\n";
    std::cout << "5. Return a book (TODO)\n";
    std::cout << "6. Save library to file (TODO)\n";
    std::cout << "7. Load library from file (TODO)\n\n";

    std::cout << "0. Exit (TODO)\n\n";

    std::cout << "Choose an option: ";
}

std::optional<int> CommandLineInterface::getUserMenuSelection(int minValue, int maxValue) const
{
    int input;
    std::cin >> input;

    // test error scenarios
    if(std::cin.fail() || input < minValue || input > maxValue) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1;31mERROR:\033[0m Invalid input.\n";
        return {};
    }

    std::cin.ignore(1000, '\n');
    return input; // success
}
