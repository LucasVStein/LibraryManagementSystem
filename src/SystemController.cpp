#include "SystemController.hpp"

SystemController::SystemController(std::string path): data_path(path) {}

void SystemController::setup()
{
    // if data exists -> load, if it does not exist -> continue with empty library
    if(std::filesystem::is_regular_file(data_path)) {
        try {
            library.load(data_path);
        }
        catch(const std::exception& e) {
            std::cout << "\033[1;31mERROR:\033[0m Failed to load data.\n";
        }
    }
    else std::cout << "\033[1;31mERROR:\033[0m Failed to load data.\n";
}

void SystemController::mainLoop() {
    int input = -1;
    do {
        std::cout << '\n';
        CommandLineInterface::getInstance().startMenu();
        auto res = CommandLineInterface::getInstance().getUserMenuSelection(0, 7);

        if(res.has_value()) {
            input = res.value();
            switch(input) {
            case 1: // add book
                addBook();
                break;

            case 2: // remove book
                removeBook();
                break;

            case 3: // list all books
                std::cout << '\n';
                CommandLineInterface::getInstance().listBooks();
                library.show();
                CommandLineInterface::getInstance().lineBreak();
                break;

            case 4: // list available books
                listBooksByAvailability(true);
                break;

            case 5: // list unavailable books
                listBooksByAvailability(false);
                break;

            case 6: // search for book
                search();
                break;

            case 7: // borrow book
                borrowBook();
                break;

            case 8: // return book
                returnBook();
                break;

            case 9: // save library
                try {
                    library.save(data_path);
                    std::cout << "\n\033[1;32mSUCCESS:\033[0m Saved data successfully.\n";
                }
                catch(const std::exception& e) {
                    std::cout << "\n\033[1;31mERROR:\033[0m Failed to save data.\n";
                }
                break;
            
            default:
                break;
            }
        }
        else std::cout << "\n\033[1;31mERROR:\033[0m Invalid input.\n";
    } while(input != 0);

    exit();
}

void SystemController::exit() {
    CommandLineInterface::getInstance().lineBreak();
    std::optional<int> input;
    do {
        CommandLineInterface::getInstance().exitMenu();
        input = CommandLineInterface::getInstance().getUserMenuSelection(1, 2);
        if(!input.has_value()) std::cout << "\n\033[1;31mERROR:\033[0m Invalid input.\n";
    } while(!input.has_value());

    if(input.value() == 1) {
        try {
            library.save(data_path);
            std::cout << "\n\033[1;32mSUCCESS:\033[0m Saved data successfully.\n";
        }
        catch(const std::exception& e) {
            std::cout << "\n\033[1;31mERROR:\033[0m Failed to save data.\n";
        }
    }
    std::cout << "\n\033[1;32mLibrary Management System shut down.\033[0m\n";
}

void SystemController::addBook() {
    std::cout << '\n';
    CommandLineInterface::getInstance().addBookMenu(1);

    // get book title
    CommandLineInterface::getInstance().addBookMenu(2);
    auto title = CommandLineInterface::getInstance().getStringInput();
    while(!title.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        CommandLineInterface::getInstance().addBookMenu(2);
        title = CommandLineInterface::getInstance().getStringInput();
    }
    
    // get book author
    CommandLineInterface::getInstance().addBookMenu(3);
    auto author = CommandLineInterface::getInstance().getStringInput();
    while(!author.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        CommandLineInterface::getInstance().addBookMenu(3);
        author = CommandLineInterface::getInstance().getStringInput();
    }

    // get book release year
    CommandLineInterface::getInstance().addBookMenu(4);
    auto year = CommandLineInterface::getInstance().getIntInput();
    while(!year.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input.\n";
        CommandLineInterface::getInstance().addBookMenu(4);
        year = CommandLineInterface::getInstance().getIntInput();
    }

    // confirm input
    std::cout << '\n';
    CommandLineInterface::getInstance().addBookMenu(5);
    std::cout << "Title: " + title.value() + '\n';
    std::cout << "Author: " + author.value() + '\n';
    std::cout << "Year: " + std::to_string(year.value()) + '\n';
    CommandLineInterface::getInstance().addBookMenu(6);

    CommandLineInterface::getInstance().addBookMenu(7);
    auto input = CommandLineInterface::getInstance().getUserMenuSelection(1, 2);
    while(!input.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input.\n";
        CommandLineInterface::getInstance().addBookMenu(7);
        input = CommandLineInterface::getInstance().getUserMenuSelection(1, 2);
    }

    if(input.value() == 1) {
        library.addBook({title.value(), author.value(), year.value()});
        std::cout << "\n\033[1;32mSUCCESS:\033[0m Book added to library.\n";
    }
}

void SystemController::removeBook() {
    std::cout << '\n';
    CommandLineInterface::getInstance().removeBook();
    auto id = CommandLineInterface::getInstance().getIntInput();
    while(!id.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input.\n";
        std::cout << "Book id: ";
        id = CommandLineInterface::getInstance().getIntInput();
    }

    auto res = library.removeBook(id.value());
    if(res) std::cout << "\n\033[1;32mSUCCESS:\033[0m Book " + std::to_string(id.value()) + " was removed.\n";
    else std::cout << "\n\033[1;31mERROR:\033[0m Book " + std::to_string(id.value()) + " not possible to remove.\n";
}

void SystemController::search() {
    std::cout << '\n';
    CommandLineInterface::getInstance().searchMenu(true);
    auto input = CommandLineInterface::getInstance().getUserMenuSelection(1, 4);
    while(!input.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input.\n\n";
        CommandLineInterface::getInstance().searchMenu(false);
        input = CommandLineInterface::getInstance().getUserMenuSelection(1, 4);
    }

    switch(input.value()) {
    case 1: // id
        searchById();
        break;

    case 2: // title
        searchByTitle();
        break;

    case 3: // author
        searchByAuthor();
        break;

    case 4: // year
        searchByYear();
        break;
    
    default:
        break;
    }
}

void SystemController::borrowBook() {
    std::cout << '\n';
    CommandLineInterface::getInstance().borrowBook();
    auto id = CommandLineInterface::getInstance().getIntInput();
    while(!id.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        std::cout << "Book id: ";
        id = CommandLineInterface::getInstance().getIntInput();
    }

    auto result = library.changeBookAvailability(id.value(), false);
    if(result.has_value() && result.value()) std::cout << "\n\033[1;32mSUCCESS:\033[0m Book " + std::to_string(id.value()) + " is now unavailable.\n";
    else if(result.has_value() && !result.value()) std::cout << "\n\033[1;31mERROR:\033[0m Book " + std::to_string(id.value()) + " is already unavailable.\n";
    else std::cout << "\n\033[1;31mERROR:\033[0m Book " + std::to_string(id.value()) + " does not exist.\n";
}

void SystemController::returnBook() {
    std::cout << '\n';
    CommandLineInterface::getInstance().returnBook();
    auto id = CommandLineInterface::getInstance().getIntInput();
    while(!id.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        std::cout << "Book id: ";
        id = CommandLineInterface::getInstance().getIntInput();
    }

    auto result = library.changeBookAvailability(id.value(), true);
    if(result.has_value() && result.value()) std::cout << "\n\033[1;32mSUCCESS:\033[0m Book " + std::to_string(id.value()) + " is now available.\n";
    else if(result.has_value() && !result.value()) std::cout << "\n\033[1;31mERROR:\033[0m Book " + std::to_string(id.value()) + " is already available.\n";
    else std::cout << "\n\033[1;31mERROR:\033[0m Book " + std::to_string(id.value()) + " does not exist.\n";
}

void SystemController::listBooksByAvailability(bool availability) const {
    std::cout << '\n';
    CommandLineInterface::getInstance().listBooks();
    auto searchResult = library.searchBooks(4, availability);
    library.showConditional(searchResult);
    CommandLineInterface::getInstance().lineBreak();
}

void SystemController::searchById() {
    std::cout << "Book id: ";
    auto id = CommandLineInterface::getInstance().getIntInput();
    while(!id.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        std::cout << "Book id: ";
        id = CommandLineInterface::getInstance().getIntInput();
    }

    // get results
    auto results = library.searchBooks(0, id.value());

    // output results
    std::cout << '\n';
    CommandLineInterface::getInstance().searchResult();
    library.showConditional(results);
}

void SystemController::searchByTitle() {
    std::cout << "Title: ";
    auto title = CommandLineInterface::getInstance().getStringInput();
    while(!title.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        std::cout << "Title: ";
        title = CommandLineInterface::getInstance().getStringInput();
    }

    // get results
    auto results = library.searchBooks(1, title.value());

    // output results
    std::cout << '\n';
    CommandLineInterface::getInstance().searchResult();
    library.showConditional(results);
}

void SystemController::searchByAuthor() {
    std::cout << "Author: ";
    auto author = CommandLineInterface::getInstance().getStringInput();
    while(!author.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        std::cout << "Author: ";
        author = CommandLineInterface::getInstance().getStringInput();
    }

    // get results
    auto results = library.searchBooks(2, author.value());

    // output results
    std::cout << '\n';
    CommandLineInterface::getInstance().searchResult();
    library.showConditional(results);
}

void SystemController::searchByYear() {
    std::cout << "Year: ";
    auto year = CommandLineInterface::getInstance().getIntInput();
    while(!year.has_value()) {
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        std::cout << "Year: ";
        year = CommandLineInterface::getInstance().getIntInput();
    }

    // get results
    auto results = library.searchBooks(3, year.value());

    // output results
    std::cout << '\n';
    CommandLineInterface::getInstance().searchResult();
    library.showConditional(results);
}
