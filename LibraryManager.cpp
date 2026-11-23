#include "LibraryManager.h"
#include <iostream>
#include <stdexcept>

LibraryManager::~LibraryManager() 
{
    for (auto item : inventory) 
    {
        delete item;
    }
    inventory.clear();
}

void LibraryManager::addItem(MediaItem* item) 
{
    inventory.push_back(item);
}

LibraryManager& LibraryManager::operator+=(MediaItem* item) 
{
    addItem(item);
    return *this;
}

void LibraryManager::removeItem(int id) 
{
    for (size_t i = 0; i < inventory.size(); i++) 
    {
        if (*inventory[i] == MediaItem(id)) 
        {
            if(inventory[i]->getIsBorrowed())
            {
                throw runtime_error("Nie mozna usunac pozycji, poniewaz jest aktualnie wypozyczona!");
            } 
            delete inventory[i];
            inventory.erase(inventory.begin() + i);
            cout << "Usunieto pozycje o ID: " << id << endl;
            return;
        }
    }
    throw out_of_range("Blad: Nie znaleziono pozycji o podanym ID!");
}

void LibraryManager::showAll() const 
{
    if (inventory.empty()) 
    {
        cout << "Biblioteka jest pusta" << endl;
        return;
    }
    cout << "\n--- ZASOBY BIBLIOTEKI ---" << endl;
    for (const auto& item : inventory) 
    {
        item->printDetails();
        cout << endl;
    }
    cout << "-------------------------\n" << endl;
}

void LibraryManager::addUser(int id, string name) 
{
    users.push_back(User(id, name));
    cout << "Dodano uzytkownika: " << name << endl;
}

void LibraryManager::showUsers() const 
{
    if (users.empty()) 
    {
        cout << "Brak zarejestrowanych uzytkownikow." << endl;
        return;
    }
    cout << "\n--- LISTA UZYTKOWNIKOW ---" << endl;
    for (const auto& user : users) 
    {
        user.showUserInfo();
    }
    cout << "--------------------------\n" << endl;
}

void LibraryManager::borrowItem(int userId, int mediaId) 
{
    User* targetUser = nullptr;
    for (auto& user : users) 
    {
        if (user.getUserId() == userId) 
        {
            targetUser = &user;
            break;
        }
    }

    if (!targetUser) throw out_of_range("Nie znaleziono uzytkownika o podanym ID!");

    MediaItem* targetMedia = nullptr;
    for (auto item : inventory) 
    {
        if (item->getId() == mediaId) 
        {
            targetMedia = item;
            break;
        }
    }
    if (!targetMedia) throw out_of_range("Nie znaleziono pozycji o podanym ID!");
    
    if (targetMedia->getIsBorrowed()) 
    {
        throw runtime_error("Ta pozycja jest juz wypozyczona przez kogos innego!");
    }
    targetMedia->setIsBorrowed(true);
    targetUser->borrowMedia(targetMedia);
    cout << "Wypozyczono '" << targetMedia->getTitle() << "' uzytkownikowi " << targetUser->getName() << "." << endl;
}

void LibraryManager::returnItem(int userId, int mediaId) 
{
    for (auto& user : users) 
    {
        if (user.getUserId() == userId) 
        {
            user.returnMedia(mediaId);
            cout << "Sukces! Zwrocono pozycje o ID: " << mediaId << endl;
            return;
        }
    }
    throw out_of_range("Nie znaleziono uzytkownika o podanym ID!");
}
