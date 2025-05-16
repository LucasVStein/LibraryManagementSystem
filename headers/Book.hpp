#pragma once

#include <iostream>
#include <string>

/*
* Class that implements the Book logic.
* Contains:
*  -      (string) title: title of this book object;
*  -     (string) author: author of this book object;
*  - (unsigned int) year: release year for this book object;
*  -  (bool) isAvailable: if the book is available or not (borrowed).
*/
class Book {
    std::string title;
    std::string author;
    unsigned int year;
    bool isAvailable;

    public:

    /* ctors */
    Book(std::string, std::string, unsigned int, bool = true);
    Book() = delete;

    /* getters */
    std::string getTitle() const;
    std::string getAuthor() const;
    unsigned int getYear() const;
    bool getIsAvailable() const;

    /* utils */
    [[maybe_unused]] void show() const;
};
