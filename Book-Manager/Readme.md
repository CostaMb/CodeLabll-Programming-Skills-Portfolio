# Book Manager – Code Explanation

The Book Manager is a C++ program that allows users to manage a collection of books. I created this program to practise object-oriented programming and file handling.

The program uses a `Book` class to store information about each book, including its title, author, number of pages, ID and availability. The `Book.h` file defines the class, while `Book.cpp` contains the constructors, getters and setters used to access and update book information.

The `main.cpp` file contains the main menu and the program functions. Users can view all books, search for a book by title or ID, add new books, update book details, delete books and view available books.

The program uses a vector to store book objects and file handling to read information from `bookData.txt`. The `saveBooks()` function saves changes to the file, allowing the information to remain available when the program is closed and reopened.

I included basic input validation when entering the number of pages and checking whether a book ID already exists. I also tested the main functions to check that books could be displayed, searched, added, updated, deleted and saved correctly.

## Development Tools and AI Acknowledgement

I used Visual Studio Code to write, compile and test the program. I also used Microsoft Copilot to help with coding, solving problems and understanding C++ concepts.