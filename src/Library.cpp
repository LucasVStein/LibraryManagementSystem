#include "Library.hpp"

using json = nlohmann::json;

void Library::load(std::string path) {
    std::ifstream ifile(path);

    if(!ifile.is_open()) {
        throw std::runtime_error("[ERROR] Error while loading library data.");
    }

    try {
        json j;
        ifile >> j;
        books = j.get<std::vector<Book>>();
    }
    catch(const std::exception& e) {
        throw std::runtime_error("[ERROR] Error while loading library data.");
    }    
}

void Library::save(const std::string& path) const {
    std::ofstream ofile(path);

    if(!ofile.is_open()) {
        throw std::runtime_error("[ERROR] Error while saving library data.");
    }

    try {
        json j = books;
        ofile << j.dump(4);
    }
    catch(const std::exception& e) {
        throw std::runtime_error("[ERROR] Error while saving library data.");
    }
}

void Library::show() const {
    if(books.empty()) std::cout << "Empty\n";
    for(const Book& b : books) {
        b.show();
    }
}
