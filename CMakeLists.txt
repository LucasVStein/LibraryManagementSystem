cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# include header files
include_directories(${PROJECT_SOURCE_DIR}/headers)

# add executable from source files
add_executable(library.exe
    src/main.cpp
    src/Book.cpp
)
