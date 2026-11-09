#include "MediaItem.h"

MediaItem::MediaItem(int id, string title, string author): id(id), title(title), author(author) {}

int MediaItem::getId() const 
{
    return id;
}

string MediaItem::getTitle() const 
{
    return title;
}

string MediaItem::getAuthor() const 
{
    return author;
}

void MediaItem::printDetails() const 
{
    cout << "[ID: " << id << "] " << title << " - " << author << endl;
}

bool MediaItem::operator==(const MediaItem& other) const 
{
    return this->id == other.id;
}