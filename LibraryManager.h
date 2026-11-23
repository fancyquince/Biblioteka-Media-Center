#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <vector>
#include "MediaItem.h"
#include "User.h"

class LibraryManager 
{
private:
    vector<MediaItem*> inventory;
    vector<User> users;

public:
    ~LibraryManager();

    void addItem(MediaItem* item);
    void removeItem(int id);
    void showAll() const;

    void addUser(int id, string name);
    void showUsers() const;
    void borrowItem(int userId, int mediaId);
    void returnItem(int userId, int mediaId);

    LibraryManager& operator+=(MediaItem* item);
};

#endif