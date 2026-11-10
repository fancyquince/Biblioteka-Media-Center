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
            delete inventory[i];
            inventory.erase(inventory.begin() + i);
            cout << "Usunięto pozycje o ID: " << id << endl;
            return;
        }
    }
    throw out_of_range("Błąd: Nie znaleziono pozycji o podanym ID!");
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