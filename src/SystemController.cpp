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
    int input;
    do {
        std::cout << '\n';
        CommandLineInterface::getInstance().startMenu();
        auto res = CommandLineInterface::getInstance().getUserMenuSelection(0, 6);

        if(res.has_value()) {
            input = res.value();
            switch(input) {
            case 1: // add book
                addBook();
                break;

            case 2: // list all books
                std::cout << '\n';
                CommandLineInterface::getInstance().listBooks();
                library.show();
                CommandLineInterface::getInstance().lineBreak();
                break;

            case 3: // search for book
                // todo
                break;

            case 4: // borrow book
                // todo
                break;

            case 5: // return book
                // todo
                break;

            case 6: // save library
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
    } while(input != 0);

    exit();
}

void SystemController::exit() {
    CommandLineInterface::getInstance().lineBreak();
    std::optional<int> input;
    do {
        CommandLineInterface::getInstance().exitMenu();
        input = CommandLineInterface::getInstance().getUserMenuSelection(1, 2);
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
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
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
        std::cout << "\n\033[1;31mERROR:\033[0m Invalid input, please try again.\n";
        CommandLineInterface::getInstance().addBookMenu(7);
        input = CommandLineInterface::getInstance().getUserMenuSelection(1, 2);
    }

    if(input.value() == 1) {
        library.addBook({title.value(), author.value(), year.value()});
        std::cout << "\n\033[1;32mSUCCESS:\033[0m Book added to library.\n";
    }
}
