
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Book.h"

using namespace std;

// Name of the file used to store book records.
const string FILE_NAME = "bookData.txt";

// Reads book records from the file and creates Book objects.
vector<Book> loadBooks() {
    vector<Book> books;
    ifstream file(FILE_NAME);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string title, author, pages, id, available;

        // Reads the five fields stored for each book.
        if (getline(ss, title, ',') &&
            getline(ss, author, ',') &&
            getline(ss, pages, ',') &&
            getline(ss, id, ',') &&
            getline(ss, available)) {
            try {
                books.emplace_back(title, author, stoi(pages),
                                   id, available == "true");
            } catch (...) {
                cout << "Invalid book record skipped.\n";
            }
        }
    }
    return books;
}

// Saves the current book collection to the data file.
bool saveBooks(const vector<Book>& books) {
    ofstream file(FILE_NAME);

    if (!file) {
        cout << "Could not save books.\n";
        return false;
    }

    for (const Book& b : books) {
        file << b.getTitle() << ',' << b.getAuthor() << ','
             << b.getPages() << ',' << b.getId() << ','
             << (b.isAvailable() ? "true" : "false") << '\n';
    }
    return true;
}

// Displays the details of a single book.
void displayBook(const Book& b) {
    cout << "\nID: " << b.getId()
         << "\nTitle: " << b.getTitle()
         << "\nAuthor: " << b.getAuthor()
         << "\nPages: " << b.getPages()
         << "\nAvailable: " << (b.isAvailable() ? "Yes" : "No")
         << "\n";
}

// Displays all books stored in the collection.
void viewAllBooks(const vector<Book>& books) {
    if (books.empty()) cout << "No books found.\n";
    for (const Book& b : books) displayBook(b);
}

// Searches for a book using its title or ID.
void searchBook(const vector<Book>& books) {
    string term;
    cout << "Enter book title or ID: ";
    getline(cin, term);
    bool found = false;

    for (const Book& b : books) {
        if (b.getTitle().find(term) != string::npos ||
            b.getId() == term) {
            displayBook(b);
            found = true;
        }
    }
    if (!found) cout << "Book not found.\n";
}

// Adds a new book after checking that its ID is unique.
void addBook(vector<Book>& books) {
    string id, title, author;
    cout << "Enter ID: ";
    getline(cin, id);

    for (const Book& b : books) {
        if (b.getId() == id) {
            cout << "ID already exists.\n";
            return;
        }
    }

    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);

    int pages;
    cout << "Enter pages: ";

    if (!(cin >> pages) || pages <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid page count.\n";
        return;
    }
    cin.ignore(10000, '\n');

    books.emplace_back(title, author, pages, id, true);

    // Reverts the addition if saving fails.
    if (saveBooks(books)) cout << "Book added.\n";
    else books.pop_back();
}

// Updates the title, author and page count of a book.
void updateBook(vector<Book>& books) {
    string id;
    cout << "Enter ID to update: ";
    getline(cin, id);

    for (Book& b : books) {
        if (b.getId() == id) {
            string title, author;
            int pages;

            cout << "New title: ";
            getline(cin, title);
            cout << "New author: ";
            getline(cin, author);
            cout << "New page count: ";

            if (!(cin >> pages) || pages <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid page count.\n";
                return;
            }
            cin.ignore(10000, '\n');

            b.setTitle(title);
            b.setAuthor(author);
            b.setPages(pages);

            if (saveBooks(books)) cout << "Book updated.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Removes a book using its ID and saves the changes.
void deleteBook(vector<Book>& books) {
    string id;
    cout << "Enter ID to delete: ";
    getline(cin, id);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            Book removed = *it;
            books.erase(it);

            // Restores the book if saving fails.
            if (saveBooks(books)) cout << "Book deleted.\n";
            else books.push_back(removed);
            return;
        }
    }
    cout << "Book not found.\n";
}

// Displays only books marked as available.
void viewAvailableBooks(const vector<Book>& books) {
    bool found = false;

    for (const Book& b : books) {
        if (b.isAvailable()) {
            displayBook(b);
            found = true;
        }
    }
    if (!found) cout << "No available books.\n";
}

// Runs the menu and calls the selected function.
int main() {
    vector<Book> books = loadBooks();
    int choice;

    do {
        cout << "\n=== BOOK MANAGER ===\n"
             << "1. View all books\n"
             << "2. Search book\n"
             << "3. Add book\n"
             << "4. Update book\n"
             << "5. Delete book\n"
             << "6. View available books\n"
             << "7. Save and exit\n"
             << "Choice: ";

        // Checks that the menu choice is a number.
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a number.\n";
            continue;
        }
        cin.ignore(10000, '\n');

        // Executes the selected menu option.
        switch (choice) {
            case 1: viewAllBooks(books); break;
            case 2: searchBook(books); break;
            case 3: addBook(books); break;
            case 4: updateBook(books); break;
            case 5: deleteBook(books); break;
            case 6: viewAvailableBooks(books); break;
            case 7:
                if (saveBooks(books)) cout << "Books saved.\n";
                break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
