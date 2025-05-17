#include "SystemController.hpp"

SystemController::SystemController(std::string path): data_path(path) {}

void SystemController::setup()
{
    // if data exists -> load, if it does not exist -> continue with empty library
    if(std::filesystem::is_regular_file(data_path)) {
        try {
            library.load(data_path);
        }
        catch(const std::exception& e) {
            std::cout << "\033[1;31mERROR:\033[0m Failed to load data.\n";
        }
    }
    else std::cout << "\033[1;31mERROR:\033[0m Failed to load data.\n";
}

void SystemController::mainLoop() {
    int input;
    do {
        std::cout << '\n';
        CommandLineInterface::getInstance().startMenu();
        auto res = CommandLineInterface::getInstance().getUserMenuSelection(0, 6);

        if(res.has_value()) {
            input = res.value();
            switch(input) {
            case 1: // add book
                // todo
                break;

            case 2: // list all books
                std::cout << '\n';
                CommandLineInterface::getInstance().listBooks();
                library.show();
                CommandLineInterface::getInstance().lineBreak();
                break;

            case 3: // search for book
                // todo
                break;

            case 4: // borrow book
                // todo
                break;

            case 5: // return book
                // todo
                break;

            case 6: // save library
                try {
                    library.save(data_path);
                    std::cout << "\n\033[1;32mSUCCESS:\033[0m Saved data successfully.\n";
                }
                catch(const std::exception& e) {
                    std::cout << "\n\033[1;31mERROR:\033[0m Failed to save data.\n";
                }
                break;
            
            default:
                break;
            }
        }
    } while(input != 0);
}
