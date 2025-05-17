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

void Library::save(const std::string& path) const {
    json j = books;
    std::ofstream ofile(path);
    if(ofile.is_open()) ofile << j.dump(4);
}

void Library::show() const {
    for(const Book& b : books) {
        b.show();
    }
}
