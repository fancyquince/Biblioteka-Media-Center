#include <iostream>
#include <string>
#include <stdexcept>
#include "Book.h"
#include "EBook.h"
#include "LibraryManager.h"

using namespace std;

int main()
{
    LibraryManager manager;
    int choice;

    manager += new Book(1, "Wladca Pierscieni", "J.R.R. Tolkien", 1200);
    manager += new EBook(2, "Wiedzmin", "Andrzej Sapkowski", 3.5);

    while (true) 
    {
        cout << "=== MENU MEDIA CENTER ===" << endl;
        cout << "1. Wyswietl wszystkie pozycje" << endl;
        cout << "2. Dodaj ksiazke" << endl;
        cout << "3. Dodaj e-booka" << endl;
        cout << "4. Usun pozycje po ID" << endl;
        cout << "5. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;

        if (choice == 5) 
        {
            cout << "Zamykanie programu..." << endl;
            break;
        }

        switch (choice) 
        {
            case 1:
                manager.showAll();
                break;
            case 2: {
                int id, pages;
                string title, author;
                cout << "Podaj ID: "; cin >> id;
                cin.ignore();
                cout << "Podaj tytul: "; getline(cin, title);
                cout << "Podaj autora: "; getline(cin, author);
                cout << "Liczba stron: "; cin >> pages;
                
                manager += new Book(id, title, author, pages);
                cout << "Dodano ksiazke!" << endl;
                break;
            }
            case 3: 
            {
                int id;
                double sizeMB;
                string title, author;
                cout << "Podaj ID: "; cin >> id;
                cin.ignore();
                cout << "Podaj tytul: "; getline(cin, title);
                cout << "Podaj autora: "; getline(cin, author);
                cout << "Rozmiar pliku (MB): "; cin >> sizeMB;
                
                manager += new EBook(id, title, author, sizeMB);
                cout << "Dodano e-booka!" << endl;
                break;
            }
            case 4: 
            {
                int id;
                cout << "Podaj ID do usuniecia: ";
                cin >> id;
                
                try {
                    manager.removeItem(id);
                } catch (const out_of_range& e) {
                    cout << "\n>>> " << e.what() << " <<<\n"; 
                }
                break;
            }
            default:
                cout << "Nieprawidlowa opcja!" << endl;
        }
        cout << endl;
    }

    return 0;
}