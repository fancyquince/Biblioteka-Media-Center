#ifndef EBOOK_H
#define EBOOK_H
#include "MediaItem.h"

class EBook : public MediaItem 
{
private:
    double fileSizeMB;

public:
    EBook(int id, string title, string author, double fileSizeMB);
    
    void printDetails() const override;
};

#endif