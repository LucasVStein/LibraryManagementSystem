# 📚 Library Management System

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![CMake](https://img.shields.io/badge/build-CMake-blue)

A simple **console-based Library Management System** written in modern C++. It allows adding, listing, searching, borrowing, returning, and removing books. Data is persisted to a JSON file between sessions.

---

## ✅ Features

- Add new books to the collection
- Remove existing books
- Search by **title**, **author**, or **year**
- Borrow and return books
- List all books
- Save and load book data to/from a JSON file
- CLI
- Modular design: `Book`, `Library`, `CLI`, and `SystemController`

---

## 📁 Project Structure

LibraryManagementSystem/
│
├── headers/ # All header files
│ ├── Book.hpp
│ ├── Library.hpp
│ ├── CommandLineInterface.hpp
│ └── SystemController.hpp
│
├── src/ # All implementation files
│ ├── Book.cpp
│ ├── Library.cpp
│ ├── CommandLineInterface.cpp
│ ├── SystemController.cpp
│ └── main.cpp
│
├── CMakeLists.txt # Build configuration
├── README.md # Project documentation
└── .gitignore

---

## ⚙️ Build Instructions

### 📦 Requirements

- C++17 compatible compiler (e.g. `g++`, `clang++`)
- CMake (v3.10 or higher)

### 🛠️ Build steps

```bash
# Clone or extract the project
cd LibraryManagementSystem

# Create and enter build directory
mkdir build && cd build

# Run CMake and build
cmake ..
make
```

---

## 🚀 Run the Program

```bash
./bin/library.exe
```
This will launch the CLI.

### 💾 Data Storage

All book data is saved to a JSON file at:
```bash
../data/lib.json
```
The file is created if it doesn’t exist.

### 🧪 Example JSON Data

```json
[
  {
    "title": "The Hobbit",
    "author": "J.R.R. Tolkien",
    "year": 1937,
    "available": true
  },
  {
    "title": "1984",
    "author": "George Orwell",
    "year": 1949,
    "available": false
  },
  {
    "title": "To Kill a Mockingbird",
    "author": "Harper Lee",
    "year": 1960,
    "available": true
  },
  {
    "title": "Brave New World",
    "author": "Aldous Huxley",
    "year": 1932,
    "available": true
  },
  {
    "title": "Fahrenheit 451",
    "author": "Ray Bradbury",
    "year": 1953,
    "available": false
  }
]
```
