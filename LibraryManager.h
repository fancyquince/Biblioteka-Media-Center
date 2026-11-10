#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <vector>
#include "MediaItem.h"

class LibraryManager 
{
private:
    vector<MediaItem*> inventory;

public:
    ~LibraryManager();

    void addItem(MediaItem* item);
    void removeItem(int id);
    void showAll() const;

    LibraryManager& operator+=(MediaItem* item);
};

#endif