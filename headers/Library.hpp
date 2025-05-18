#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <variant>
#include <nlohmann/json.hpp>

#include "Library.hpp"
#include "Book.hpp"

/*
* Class that implements the general Library logic.
* Contains:
*  - (vector<Book>) books: vector containing all the book objects belonging to this library.
*/
class Library {
    std::vector<Book> books;

    public:

    /* ctors */
    Library() = default;

    /* utils */
    void addBook(Book);
    void removeBook(unsigned int);
    void load(std::string);
    void save(const std::string&) const;
    void changeBookAvailability(unsigned int, bool);

    void show() const;
    void showConditional(std::vector<unsigned int>) const;

    std::vector<unsigned int> searchBooks(unsigned int, std::variant<unsigned int, std::string>);
};
