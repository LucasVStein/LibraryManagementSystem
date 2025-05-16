#pragma once

#include <iostream>
#include <vector>

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
    Library();
};
