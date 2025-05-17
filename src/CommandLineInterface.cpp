#include "CommandLineInterface.hpp"

CommandLineInterface &CommandLineInterface::getInstance()
{
    static CommandLineInterface instance;
    return instance;
}

void CommandLineInterface::startMenu() const {
    std::cout << "\033[1;32m==============================\n";
    std::cout << "  Library Management System\n";
    std::cout << "==============================\033[0m\n\n";

    std::cout << "1. Add a new book (TODO)\n";
    std::cout << "2. List all books\n";
    std::cout << "3. Search for a book (TODO)\n";
    std::cout << "4. Borrow a book (TODO)\n";
    std::cout << "5. Return a book (TODO)\n";
    std::cout << "6. Save library to file\n";

    std::cout << "0. Exit\n\n";

    std::cout << "\033[1;32mChoose an option: \033[0m";
}

void CommandLineInterface::listBooks() const {
    std::cout << "\033[1;32m======  List of Books  =======\033[0m\n";
}

void CommandLineInterface::lineBreak() const {
    std::cout << "\033[1;32m==============================\033[0m\n";
}

void CommandLineInterface::exitMenu() const {
    std::cout << "Do you wish to save before closing?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n\n";

    std::cout << "\033[1;32mChoose an option: \033[0m";
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
