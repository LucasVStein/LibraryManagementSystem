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

    std::cout << "1. Add a new book\n";
    std::cout << "2. Remove book\n";
    std::cout << "3. List all books\n";
    std::cout << "4. Search for a book (TODO)\n";
    std::cout << "5. Borrow a book\n";
    std::cout << "6. Return a book\n";
    std::cout << "7. Save library to file\n";

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

void CommandLineInterface::addBookMenu(unsigned int menuOption) const {
    switch(menuOption) {
    case 1:
        std::cout << "\033[1;32m======  Add Book  =======\033[0m\n\n";
        break;

    case 2:
        std::cout << "Title: ";
        break;

    case 3:
        std::cout << "Author: ";
        break;

    case 4:
        std::cout << "Release year: ";
        break;

    case 5:
        std::cout << "\033[1;32mNew Book ========\033[0m\n";
        break;

    case 6:
        std::cout << "\033[1;32m=================\033[0m\n";
        break;

    case 7:
        std::cout << "\033[1;32mDo you want to add this book?\033[0m\n";
        std::cout << "1. Yes\n";
        std::cout << "2. No\n\n";

        std::cout << "\033[1;32mChoose an option: \033[0m\n";
        break;
    
    default:
        break;
    }
}

void CommandLineInterface::removeBook() const {
    std::cout << "\033[1;32m======  Remove Book  =======\033[0m\n\n";
    std::cout << "Book id: ";
}

void CommandLineInterface::borrowBook() const {
    std::cout << "\033[1;32m======  Borrow Book  =======\033[0m\n\n";
    std::cout << "Book id: ";
}

void CommandLineInterface::returnBook() const {
    std::cout << "\033[1;32m======  Return Book  =======\033[0m\n\n";
    std::cout << "Book id: ";
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

std::optional<std::string> CommandLineInterface::getStringInput() const {
    std::string input;

    if(!std::getline(std::cin, input)) { // error scenario
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return {};
    }
    if(isWhitespaceOnlyInput(input)) return {}; // error scenario

    return input;
}

std::optional<unsigned int> CommandLineInterface::getIntInput() const {
    unsigned int input;
    std::cin >> input;

    if(std::cin.fail()) { // error scenario
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return {};
    }
    if(input > 2500) {
        std::cin.ignore(1000, '\n');
        return {};
    }

    std::cin.ignore(1000, '\n');
    return input;
}

bool CommandLineInterface::isWhitespaceOnlyInput(const std::string& input) const {
    for(char c : input) {
        if(!std::isspace(c)) return false;
    }
    return true;
}
