#pragma once

#include <iostream>

#include "Library.hpp"
#include "CommandLineInterface.hpp"

/*
* Class that handles the general logic of the application.
* For example, the main loop.
* Contains:
*  -  (Library) library: library object that contain the books data
*  - (string) data_path: ath to the file holding the library data
*/
class SystemController {
    Library library;
    const std::string data_path;

    public:

    /* ctors */
    SystemController(std::string);
    SystemController() = delete;

    /* main logic */
    void setup();
    void mainLoop();
    void exit();

    void addBook();
    void removeBook();
    void search();
    void borrowBook();
    void returnBook();

    void listBooksByAvailability(bool) const;

    /* utils */
    void searchById();
    void searchByTitle();
    void searchByAuthor();
    void searchByYear();
};
