// Biblioteka-projektIO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Book.h"
#include "User.h"
#include "Librarian.h"
#include "MainController.h"

using namespace std;

int main()
{
	vector <User> userDatabase;
	vector <Librarian> librarianDatabase;
	vector <Book> bookDatabase;
	vector <Reservation> reservationDatabase;
	string name = "Zuza";
	string password = "zuza";
	User test(name, password, {1, 1, 1970});
	Librarian test2(name, password);
	librarianDatabase.push_back(test2);
	vector <string> doKsiazki;
	vector <string> autorzy;
	doKsiazki.push_back("Gatunek: Fantasy");
	autorzy.push_back("J.R.R. Tolkien");
	name = "Wladca Perscieni, II Wieze";
	bookDatabase.push_back(Book(name ,doKsiazki,autorzy));
	for (int i = 0; i < 5; ++i)
		bookDatabase[0].createItem();
	name = "Wladca Perscieni, Druzyna Pierscienia";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	for (int i = 0; i < 8; ++i)
		bookDatabase[1].createItem();
	name = "Wladca Perscieni, Powrot Krola";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	for (int i = 0; i < 4; ++i)
		bookDatabase[2].createItem();
	autorzy.pop_back();
	autorzy.push_back("Christopher Paolini");
	name = "Eragon";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	for (int i = 0; i < 10; ++i)
		bookDatabase[3].createItem();
	name = "Najstarszy";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	for (int i = 0; i < 2; ++i)
		bookDatabase[4].createItem();
	name = "Brisingr";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	for (int i = 0; i < 4; ++i)
		bookDatabase[5].createItem();
	name = "Dziedzictwo I";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	for (int i = 0; i < 5; ++i)
		bookDatabase[6].createItem();
	name = "Dziedzictwo II";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	for (int i = 0; i < 4; ++i)
		bookDatabase[7].createItem();
	userDatabase.push_back(test);
	MainController mainController = MainController(userDatabase, librarianDatabase, bookDatabase);
	mainController.start();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
