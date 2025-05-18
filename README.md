# 📚 Library Management System

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![CMake](https://img.shields.io/badge/build-CMake-blue)

A simple **console-based Library Management System** written in modern C++. It allows adding, listing, searching, borrowing, returning, and removing books. Data is persisted to a JSON file between sessions.

---

## 📑 Table of Contents

- [📚 Library Management System](#-library-management-system)
  - [📑 Table of Contents](#-table-of-contents)
  - [✅ Features](#-features)
  - [📁 Project Structure](#-project-structure)
  - [⚙️ Build Instructions](#️-build-instructions)
    - [📦 Requirements](#-requirements)
    - [🛠️ Build steps](#️-build-steps)
  - [🚀 Run the Program](#-run-the-program)
    - [💾 Data Storage](#-data-storage)
    - [🧪 Example JSON Data](#-example-json-data)
  - [🔍 Code Overview](#-code-overview)
    - [📘 `Book`](#-book)
    - [📚 `Library`](#-library)
    - [🖥️ `CommandLineInterface` (Singleton)](#️-commandlineinterface-singleton)
    - [🧠 `SystemController`](#-systemcontroller)
    - [🔁 `main.cpp`](#-maincpp)

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

```text
LibraryManagementSystem/
│
├── headers/                # All header files
│   ├── Book.hpp
│   ├── Library.hpp
│   ├── CommandLineInterface.hpp
│   └── SystemController.hpp
│
├── src/                    # All implementation files
│   ├── Book.cpp
│   ├── Library.cpp
│   ├── CommandLineInterface.cpp
│   ├── SystemController.cpp
│   └── main.cpp
│
├── CMakeLists.txt          # Build configuration
├── README.md               # Project documentation
└── .gitignore
```

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

---

## 🔍 Code Overview

### 📘 `Book`

Represents a single book.

- **Attributes:**  
  - `title`: Title of the book  
  - `author`: Author of the book  
  - `year`: Release year  
  - `isAvailable`: Availability status

- **Key Functions:**  
  - `getTitle()`, `getAuthor()`, `getYear()`, `getIsAvailable()` – Getters  
  - `setTitle(...)`, `setAuthor(...)`, etc. – Setters  
  - `show()` – Prints book information to the console  
  - `to_json(...)`, `from_json(...)` – JSON serialization support

---

### 📚 `Library`

Handles the book collection and operations on it.

- **Attributes:**  
  - `std::vector<Book> books`: A list of all books in the system

- **Key Functions:**  
  - `addBook(...)` – Adds a new book to the collection  
  - `removeBookById(...)` – Deletes a book by its ID  
  - `borrowBook(...)` / `returnBook(...)` – Updates availability status  
  - `searchBooks()` – Searches books by title, author, or year  
  - `listBooks()` – Displays all books  
  - `save(...)` / `load(...)` – Handles persistence with JSON files

---

### 🖥️ `CommandLineInterface` (Singleton)

Implements the CLI.

- **Key Functions:**  
  - `startMenu()` – Main menu  

---

### 🧠 `SystemController`

Implements the overall system logic. Main system component.

- **Attributes:**  
  - `library` instance of the library class  
  - `data_path` path for the JSON

- **Key Functions:**  
  - `mainLoop()` – Main execution loop  
  - `setup()` – Does the setup for the system

---

### 🔁 `main.cpp`

Program entry point.

- **Key Function:**  
  - Initializes `SystemController` and starts the app by calling `mainLoop()`
