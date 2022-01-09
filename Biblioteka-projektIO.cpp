// Biblioteka-projektIO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Book.h"
#include "User.h"
#include "Librarian.h"
#include "UserFunctions.h"

using namespace std;

void start(vector <User>& userDatabase, vector <Book>& bookDatabase);

void start(vector <User>& userDatabase, vector <Book> & bookDatabase)
{
	system("cls");
	cout << "Wybierz jedna z dostepnych opcji wpisujac jej numer:\n";
	cout << "\t1. Zaloguj jako pracownik\n";
	cout << "\t2. Zaloguj jako uzytkownik\n";
	cout << "\t3. Korzystaj bez zalogowania\n";
	cout << "\t4. Zarejestruj\nTwoj wybor: ";
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
		case 1:
			break;
		case 2:
		{
			User loggedUser = userLogin(userDatabase);
			loggedUser.setIsLogged(true);
			userMenu(loggedUser, bookDatabase);
			break;
		}
		case 3:
		{
			User newUser; //Uzytkownik niezalogowany ma nazwe niezalogowany
			string name = "Niezalogowany";
			newUser.setIsLogged(false);
			newUser.setName(name);
			userMenu(newUser, bookDatabase);
			break;
		}
		case 4:
		{
			userRegistration(userDatabase);
			start(userDatabase, bookDatabase);
			break;
		}
		default:
		{
			cout << "Wybierz wlasciwa opcje!\n";
			start(userDatabase, bookDatabase);
			system("pause");
			break;
		}
	}
}

int main()
{
	vector <User> userDatabase;
	vector <Librarian> librarianDatabase;
	vector <Book> bookDatabase;
	string name = "Zuza";
	string password = "zuza";
	User test(name, password, {1, 1, 1970});
	vector <string> doKsiazki;
	vector <string> autorzy;
	doKsiazki.push_back("Gatunek: Fantasy");
	autorzy.push_back("J.R.R. Tolkien");
	name = "Wladca Perscieni, II Wieze";
	bookDatabase.push_back(Book(name ,doKsiazki,autorzy));
	name = "Wladca Perscieni, Druzyna Pierscienia";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	name = "Wladca Perscieni, Powrot Krola";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	autorzy.pop_back();
	autorzy.push_back("Christopher Paolini");
	name = "Eragon";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	name = "Najstarszy";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	name = "Brisingr";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	name = "Dziedzictwo I";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	name = "Dziedzictwo II";
	bookDatabase.push_back(Book(name, doKsiazki, autorzy));
	userDatabase.push_back(test);
	start(userDatabase, bookDatabase);
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
