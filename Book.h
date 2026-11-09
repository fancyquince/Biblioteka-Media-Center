#ifndef BOOK_H
#define BOOK_H
#include "MediaItem.h"

class Book : public MediaItem 
{
private:
    int pageCount;

public:
    Book(int id, string title, string author, int pageCount);

    void printDetails() const override;
};

#endif