#include "Library.hpp"

using json = nlohmann::json;

void Library::addBook(Book book) {
    books.push_back(book);
}

bool Library::removeBook(unsigned int id) {
    auto deleteCond = [id](const Book& book){
        return id == book.getId();
    };

    auto oldSize = books.size();
    books.erase(std::remove_if(books.begin(), books.end(), deleteCond), books.end());
    return oldSize != books.size();
}

void Library::load(std::string path)
{
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

std::optional<bool> Library::changeBookAvailability(unsigned int id, bool newIsAvailable) {
    for(auto& book : books) {
        if(book.getId() == id) {
            if(book.getIsAvailable() == newIsAvailable) return false;
            book.setIsAvailable(newIsAvailable);
            return true;
        }
    }
    return {};
}

void Library::show() const {
    if(books.empty()) std::cout << "Empty\n";
    for(const Book& b : books) {
        b.show();
    }
}

void Library::showConditional(std::vector<unsigned int> indexes) const {
    if(books.empty() || indexes.empty()) std::cout << "Empty\n";
    for(auto index : indexes) {
        if(index < books.size()) books[index].show();
    }
}

std::vector<unsigned int> Library::searchBooks(unsigned int criteria, std::variant<unsigned int, std::string, bool> searchValue) const {
    std::vector<unsigned int> searchResult;

    /* criteria: 0->id, 1->title, 2->author, 3->year, 4->isAvailable */
    switch(criteria) {
    case 0:
        for(auto ite = 0; ite < books.size(); ite++) {
            if(std::get<unsigned int>(searchValue) == books[ite].getId()) {
                searchResult.push_back(ite);
                break;
            }
        }
        break;

    case 1:
        for(auto ite = 0; ite < books.size(); ite++) {
            auto searchTitle = std::get<std::string>(searchValue);
            if(books[ite].getTitle().find(searchTitle) != std::string::npos) {
                searchResult.push_back(ite);
            }
        }
        break;

    case 2:
        for(auto ite = 0; ite < books.size(); ite++) {
            auto searchAuthor = std::get<std::string>(searchValue);
            if(books[ite].getAuthor().find(searchAuthor) != std::string::npos) {
                searchResult.push_back(ite);
            }
        }
        break;

    case 3:
        for(auto ite = 0; ite < books.size(); ite++) {
            if(std::get<unsigned int>(searchValue) == books[ite].getYear()) {
                searchResult.push_back(ite);
            }
        }
        break;

    case 4:
        for(auto ite = 0; ite < books.size(); ite++) {
            if(std::get<bool>(searchValue) == books[ite].getIsAvailable()) {
                searchResult.push_back(ite);
            }
        }
        break;
    
    default:
        break;
    }

    return searchResult;
}
