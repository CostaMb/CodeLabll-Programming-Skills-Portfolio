
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

// Defines the information stored for each book.
class Book {
private:
    // Book details and current availability.
    string title, author, id;
    int pages;
    bool available;

public:
    // Creates an empty book.
    Book();

    // Creates a book with the given details.
    Book(string title, string author, int pages,
         string id, bool available);

    // Returns book information.
    string getTitle() const;
    string getAuthor() const;
    int getPages() const;
    string getId() const;
    bool isAvailable() const;

    // Updates book information.
    void setTitle(string title);
    void setAuthor(string author);
    void setPages(int pages);
    void setAvailable(bool available);
};

#endif
