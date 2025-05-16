#include <iostream>

#include "Book.hpp"

/* app entry point */
int main() {
    Book book1("Title1", "Author1", 2022);
    Book book2("Title2", "Author2", 1990, false);

    book1.show();
    book2.show();
}
