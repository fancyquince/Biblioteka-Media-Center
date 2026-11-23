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
    manager.addUser(101, "Igor Mlynarycz");

    while (true) 
    {
        cout << "=== MENU MEDIA CENTER ===" << endl;
        cout << "1. Wyswietl wszystkie pozycje" << endl;
        cout << "2. Dodaj ksiazke" << endl;
        cout << "3. Dodaj e-booka" << endl;
        cout << "4. Usun pozycje po ID" << endl;
        cout << "5. Dodaj uzytkownika" << endl;
        cout << "6. Wyswietl uzytkownikow i ich wypozyczenia" << endl;
        cout << "7. Wypozycz pozycje" << endl;
        cout << "8. Oddaj pozycje" << endl;
        cout << "9. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;

        if (choice == 9) 
        {
            cout << "Zamykanie programu..." << endl;
            break;
        }

        try {
            switch (choice) 
            {
                case 1:
                    manager.showAll();
                    break;
                case 2: 
                {
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
                    cout << "Podaj ID do usuniecia: "; cin >> id;
                    manager.removeItem(id);
                    break;
                }
                case 5: 
                {
                    int id;
                    string name;
                    cout << "Podaj ID nowego uzytkownika: "; cin >> id;
                    cin.ignore();
                    cout << "Podaj imie i nazwisko: "; getline(cin, name);
                    manager.addUser(id, name);
                    break;
                }
                case 6:
                    manager.showUsers();
                    break;
                case 7: 
                {
                    int userId, mediaId;
                    cout << "Podaj ID uzytkownika: "; cin >> userId;
                    cout << "Podaj ID pozycji do wypozyczenia: "; cin >> mediaId;
                    manager.borrowItem(userId, mediaId);
                    break;
                }
                case 8: 
                {
                    int userId, mediaId;
                    cout << "Podaj ID uzytkownika: "; cin >> userId;
                    cout << "Podaj ID pozycji do zwrotu: "; cin >> mediaId;
                    manager.returnItem(userId, mediaId);
                    break;
                }
                default:
                    cout << "Nieprawidlowa opcja!" << endl;
            }
        } catch (const exception& e) 
        {
            cout << "\n>>> BLAD: " << e.what() << " <<<\n";
        }
    }
    return 0;
}