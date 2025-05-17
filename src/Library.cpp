#include "Library.hpp"

using json = nlohmann::json;

void Library::load(std::string path) {
    std::ifstream ifile(path);
    if(ifile.is_open()) {
        json j;
        ifile >> j;
        books = j.get<std::vector<Book>>();
    }
}

void Library::save() {
    // todo
}

void Library::show() const {
    for(const Book& b : books) {
        b.show();
    }
}
