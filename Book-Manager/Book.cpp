
#include "Book.h"

// Initialises an empty book.
Book::Book() : pages(0), available(false) {}

// Initialises a book with the supplied details.
Book::Book(string title, string author, int pages,
           string id, bool available)
    : title(title), author(author), pages(pages),
      id(id), available(available) {}

// Returns the book details.
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getPages() const { return pages; }
string Book::getId() const { return id; }
bool Book::isAvailable() const { return available; }

// Updates the book details.
void Book::setTitle(string title) { this->title = title; }
void Book::setAuthor(string author) { this->author = author; }
void Book::setPages(int pages) { this->pages = pages; }
void Book::setAvailable(bool available) {
    this->available = available;
}
