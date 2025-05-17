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
        auto res = CommandLineInterface::getInstance().getUserMenuSelection(0, 7);

        if(res.has_value()) {
            input = res.value();
            std::cout << "Input: " + std::to_string(input) + '\n';
        }
    } while(input != 0); // app main loop
}
