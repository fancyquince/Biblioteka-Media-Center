#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "MediaItem.h"

using namespace std;

class User 
{
private:
    int userId;
    string name;
    vector<MediaItem*> borrowedItems;

public:
    User(int userId, string name);

    int getUserId() const;
    string getName() const;

    void borrowMedia(MediaItem* item);
    void returnMedia(int mediaId);
    void showUserInfo() const;
};

#endif