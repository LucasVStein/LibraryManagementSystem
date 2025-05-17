cmake_minimum_required(VERSION 3.14)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# include header files
include_directories(${PROJECT_SOURCE_DIR}/headers)

# add executable from source files
add_executable(library.exe
    src/main.cpp
    src/Book.cpp
    src/Library.cpp
    src/CommandLineInterface.cpp
)

# fetch external json library
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)
target_link_libraries(library.exe PRIVATE nlohmann_json::nlohmann_json)
