#include "EBook.h"

EBook::EBook(int id, string title, string author, double fileSizeMB): MediaItem(id, title, author), fileSizeMB(fileSizeMB) {}

void EBook::printDetails() const 
{
    MediaItem::printDetails();
    cout << " [E-Book] Rozmiar: " << fileSizeMB << " MB";
}