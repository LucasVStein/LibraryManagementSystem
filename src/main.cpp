#include <iostream>
#include <filesystem>

#include "SystemController.hpp"

const std::string data_path = "../data/lib.json"; // default path to the library data

/* app entry point */
int main() {
    SystemController controller(data_path);
    controller.setup();
    controller.mainLoop();
}
