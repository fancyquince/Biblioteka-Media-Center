#include "User.h"
#include <iostream>
#include <stdexcept>

User::User(int userId, string name) : userId(userId), name(name) {}

int User::getUserId() const { return userId; }
string User::getName() const { return name; }

void User::borrowMedia(MediaItem* item) 
{
    borrowedItems.push_back(item);
}

void User::returnMedia(int mediaId) {
    for (size_t i = 0; i < borrowedItems.size(); i++) 
    {
        if (borrowedItems[i]->getId() == mediaId) {
            borrowedItems[i]->setIsBorrowed(false);
            borrowedItems.erase(borrowedItems.begin() + i);
            return;
        }
    }
    throw runtime_error("Ten uzytkownik nie ma wypozyczonej pozycji o takim ID!");
}

void User::showUserInfo() const 
{
    cout << "Uzytkownik [ID: " << userId << "] " << name << " | Wypozyczone pozycje (" << borrowedItems.size() << "):" << endl;
    if (borrowedItems.empty()) 
    {
        cout << "   - Brak wypozyczonych pozycji." << endl;
    } else 
    {
        for (const auto& item : borrowedItems) 
        {
            cout << "   - [" << item->getId() << "] " << item->getTitle() << endl;
        }
    }
}