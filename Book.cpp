#include "Book.h"

Book::Book(int id, string title, string author, int pageCount): MediaItem(id, title, author), pageCount(pageCount) {}

void Book::printDetails() const 
{
    MediaItem::printDetails();
    cout << " [Książka] Strony: " << pageCount;
}