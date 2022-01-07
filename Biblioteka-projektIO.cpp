﻿// Biblioteka-projektIO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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

void start(vector <User>& userDatabase);

void start(vector <User>& userDatabase)
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
			userLogin(userDatabase);
			break;
		}
		case 3:
		{
			//User newUser; //Uzytkownik niezalogowany ma nazwe niezalogowany
			//string name = "Niezalogowany";
			//newUser.setName(name);
			break;
		}
		case 4:
		{
			userRegistration(userDatabase);
			break;
		}
		default:
		{
			cout << "Wybierz wlasciwa opcje!\n";
			system("pause");
		}
	}
}

int main()
{
	vector <User> userDatabase;
	vector <Librarian> librarianDatabase;

	string name = "Zuza";
	string password = "zuza";
	User test(name, password, {1, 1, 1970});
	userDatabase.push_back(test);
	start(userDatabase);
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
