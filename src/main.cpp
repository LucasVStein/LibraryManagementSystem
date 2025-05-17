#include <iostream>
#include <filesystem>

#include "CommandLineInterface.hpp"
#include "Library.hpp"
#include "Book.hpp"

const std::string data_path = "../data/lib.json"; // default path to the library data

/* app entry point */
int main() {

    Library library;

    // data setup: if data exists -> load, if it does not exist -> continue with empty library
    if(std::filesystem::is_regular_file(data_path)) library.load(data_path);
    else std::cout << "\033[1;31mERROR:\033[0m Failed to load data.\n";

    // initiate UI
    int input;
    do {
        CommandLineInterface::getInstance().startMenu();
        auto res = CommandLineInterface::getInstance().getUserMenuSelection(0, 6);

        if(res.has_value()) {
            input = res.value();
            switch(input) {
            case 1: // add book
                // todo
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
                // todo
                break;
            
            default:
                break;
            }
        }
    } while(input != 0); // app main loop
}
