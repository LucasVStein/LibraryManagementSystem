#pragma once

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

/*
* Class that implements the Book logic.
* Contains:
*  -      (string) title: title of this book object;
*  -     (string) author: author of this book object;
*  - (unsigned int) year: release year for this book object;
*  -  (bool) isAvailable: if the book is available or not (borrowed).
*/
class Book {
    unsigned int id;
    std::string title;
    std::string author;
    unsigned int year;
    bool isAvailable;

    static unsigned int nextId;

    public:

    /* ctors */
    Book();
    Book(std::string, std::string, unsigned int, bool = true);

    /* getters */
    std::string getTitle() const;
    std::string getAuthor() const;
    unsigned int getYear() const;
    bool getIsAvailable() const;

    /* setters */
    void setTitle(std::string);
    void setAuthor(std::string);
    void setYear(unsigned int);
    void setIsAvailable(bool);

    /* utils */
    [[maybe_unused]] void show() const;
};

/*
* Functions needed for json conversion of class Book.
*/
void to_json(nlohmann::json&, const Book&);
void from_json(const nlohmann::json&, Book&);
