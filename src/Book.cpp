#include "Book.hpp"

using json = nlohmann::json;

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

void Book::setTitle(std::string newTitle) {
    title = std::move(newTitle);
}

void Book::setAuthor(std::string newAuthor) {
    author = std::move(newAuthor);
}

void Book::setYear(unsigned int newYear) {
    year = newYear;
}

void Book::setIsAvailable(bool newIsAvailable) {
    isAvailable = newIsAvailable;
}

void Book::show() const {
    std::string isAvailableStr = isAvailable ? "Yes" : "No";
    std::cout << "Title: " + title + ", Author: " + author + ", Year: " + std::to_string(year) + ", Availability: " + isAvailableStr + '\n';
}

void to_json(nlohmann::json& j, const Book& b) {
    j = json{
        {"title", b.getTitle()},
        {"author", b.getAuthor()},
        {"year", b.getYear()},
        {"available", b.getIsAvailable()}
    };
}

void from_json(const nlohmann::json& j, Book& b) {
    b.setTitle(j.at("title").get<std::string>());
    b.setAuthor(j.at("author").get<std::string>());
    b.setYear(j.at("year").get<unsigned int>());
    b.setIsAvailable(j.at("available").get<bool>());
}
