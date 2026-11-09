#ifndef MEDIAITEM_H
#define MEDIAITEM_H
#include <string>
#include <iostream>
using namespace std;

class MediaItem 
{
private:
    int id;
    string title;
    string author;

public:
    MediaItem(int id = 0, string title = "Brak", string author = "Brak");
    
    virtual ~MediaItem() = default;

    int getId() const;
    string getTitle() const;
    string getAuthor() const;

    virtual void printDetails() const;

    bool operator==(const MediaItem& other) const;
};

#endif