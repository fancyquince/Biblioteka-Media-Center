# Biblioteka-Media-Center
Biblioteka Media Center - Projekt zaliczeniowy C++

Autor: Igor Młynarycz

# System Zarządzania Biblioteką - Media Center (C++)

Aplikacja konsolowa służąca do zarządzania zasobami biblioteki (książkami oraz e-bookami), rejestrowania czytelników oraz obsługi wypożyczeń i zwrotów.

## Architektura projektu

Kod źródłowy został podzielony na pliki nagłówkowe (`.h`) i implementacyjne (`.cpp`) z zachowaniem zasad hermetyzacji, dziedziczenia oraz polimorfizmu:

* **`MediaItem` (`MediaItem.h`, `MediaItem.cpp`)** – klasa bazowa reprezentująca dowolną pozycję w bibliotece (ID, tytuł, autor, status wypożyczenia). Zawiera wirtualny destruktor, wirtualną metodę `printDetails()` oraz przeciążony operator porównania (`==`).
* **`Book` (`Book.h`, `Book.cpp`)** – klasa pochodna dziedzicząca po `MediaItem`, rozszerzona o atrybut `pageCount` (liczba stron). Przesłania metodę `printDetails()` przy użyciu `override`.
* **`EBook` (`EBook.h`, `EBook.cpp`)** – klasa pochodna dziedzicząca po `MediaItem`, rozszerzona o atrybut `fileSizeMB` (rozmiar pliku w MB). Przesłania metodę `printDetails()`.
* **`User` (`User.h`, `User.cpp`)** – klasa reprezentująca użytkownika biblioteki, przechowująca jego ID, imię i nazwisko oraz wektor wskaźników na aktualnie wypożyczone pozycje.
* **`LibraryManager` (`LibraryManager.h`, `LibraryManager.cpp`)** – główna klasa zarządzająca kolekcją zasobów (`vector<MediaItem*>`) oraz listą zarejestrowanych użytkowników (`vector<User>`). Implementuje przeciążony operator `+=` do dodawania nowych pozycji oraz logikę wypożyczeń i zwrotów zabezpieczoną obsługą wyjątków (`try-catch-throw`).
* **`main.cpp`** – punkt wejścia aplikacji zawierający tekstowe menu użytkownika oraz główny blok `try-catch` przechwytujący wyjątki.

Diagram klas znajduje się w pliku [UML.md](UML.md).

## Kompilacja i uruchomienie

W terminalu:

```bash
g++ -static main.cpp MediaItem.cpp Book.cpp EBook.cpp User.cpp LibraryManager.cpp -o biblioteka.exe

Uruchomienie skompilowanego programu:

.\biblioteka.exe

Przykłady działania programu:

Wyświetlanie zasobów i polimorfizm (Opcja 1):
Program iteruje po wektorze wskaźników klasy bazowej MediaItem* i wywołuje odpowiednią wersję metody printDetails() w zależności od faktycznego typu obiektu:

--- ZASOBY BIBLIOTEKI ---
[ID: 1] Wladca Pierscieni - J.R.R. Tolkien (DOSTEPNA) [Ksiazka] Strony: 1200
[ID: 2] Wiedzmin - Andrzej Sapkowski (DOSTEPNA) [E-Book] Rozmiar: 3.5 MB
-------------------------

Wypożyczenie i podgląd konta użytkownika (Opcje 7 oraz 6):
Po wypożyczeniu pozycji o ID 1 przez użytkownika o ID 101 (Jan Kowalski), status książki zmienia się na (WYPOZYCZONA), a pozycja pojawia się na liście wypożyczeń czytelnika:

--- LISTA UZYTKOWNIKOW ---
Uzytkownik [ID: 101] Igor Młynarycz | Wypozyczone pozycje (1):
   - [1] Wladca Pierscieni
--------------------------

Zwrot i usuwanie pozycji z katalogu (Opcje 8 oraz 4):
Opcja 8 zdejmuje pozycję z konta użytkownika i przywraca jej status (DOSTEPNA) w bibliotece, natomiast Opcja 4 pozwala trwale usunąć wybraną książkę lub e-book z bazy po podaniu jej ID:

Sukces Zwrocono pozycje o ID: 1
Usunieto pozycje o ID: 2

Obsługa wyjątków (Opcje 4, 7, 8):
Próba wypożyczenia pozycji już zajętej, usunięcia wypożyczonej książki z bazy lub podania nieistniejącego ID powoduje wyrzucenie wyjątku i bezpieczne wyświetlenie komunikatu bez przerywania działania aplikacji:

>>> BLAD: Ta pozycja jest juz wypozyczona przez kogos innego! <<<
