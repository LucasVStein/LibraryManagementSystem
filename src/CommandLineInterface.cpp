#include "CommandLineInterface.hpp"

CommandLineInterface &CommandLineInterface::getInstance()
{
    static CommandLineInterface instance;
    return instance;
}

void CommandLineInterface::startMenu() const {
    std::cout << "\n==============================\n";
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
