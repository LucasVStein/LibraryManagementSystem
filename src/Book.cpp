#include "Book.hpp"

Book::Book(std::string newTitle, std::string newAuthor, unsigned int newYear, bool newIsAvailable)
: title(newTitle),
  author(newAuthor),
  year(newYear),
  isAvailable(newIsAvailable) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

unsigned int Book::getYear() const {
    return year;
}

bool Book::getIsAvailable() const {
    return isAvailable;
}

void Book::show() const {
    std::string isAvailableStr = isAvailable ? "Yes" : "No";
    std::cout << "Title: " + title + ", Author: " + author + ", Year: " + std::to_string(year) + ", Availability: " + isAvailableStr + '\n';
}
