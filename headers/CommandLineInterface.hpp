#pragma once

#include <iostream>
#include <optional>

/*
* Class that contains the functions to display
* all the menus to the user and contains functions to fetch
* the user inputs with error handling.
* This class uses the singleton desing pattern.
*/
class CommandLineInterface {

    /* ctors */
    CommandLineInterface() = default;

    public:

    CommandLineInterface(const CommandLineInterface&) = delete;
    CommandLineInterface& operator=(const CommandLineInterface&) = delete;

    static CommandLineInterface& getInstance(); // class access point

    /* menus */
    void startMenu() const;
    void listBooks() const;
    void lineBreak() const;

    /* user input getters */
    std::optional<int> getUserMenuSelection(int, int) const;
};
