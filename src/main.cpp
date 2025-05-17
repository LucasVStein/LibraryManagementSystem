#include <iostream>
#include <filesystem>

#include "Library.hpp"
#include "Book.hpp"

const std::string data_path = "../data/lib.json"; // default path to the library data

/* app entry point */
int main() {

    Library library;

    // data setup: if data exists -> load, if it does not exist -> continue with empty library
    if(std::filesystem::is_regular_file(data_path)) library.load(data_path);
    else std::cout << "ERROR: Failed to load data.\n";

    library.show();
}
