// Biblioteka-projektIO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Book.h"
#include "User.h"
#include "Librarian.h"

using namespace std;

void loading();

void menuUser(User & registeredUser);

void userLogin(vector <User>& userDatabase);

void registration(vector<User>& userDatabase);

void start(vector <User>& userDatabase);

void loading() //animacja ladowania
{
	for (int i = 0; i < 3; ++i) //powtorz 3 razy
	{
		Sleep(200); //zaczekaj 200 jednostek
		cout << "*" << flush; //wyswietl jedna gwiazdke
		Sleep(200); //zaczekaj
		cout << "*" << flush; //wyswietl
		Sleep(200);
		cout << "*" << flush;
		Sleep(200);
		cout << "*" << flush;
		Sleep(200);
		cout << "*" << flush;
		Sleep(200);
		cout << "\b\b\b\b\b     \b\b\b\b\b" << flush; //wymaz wszystkie gwiazdki
	}
	cout << "\n";
}

void menuUser(User & registeredUser)
{
	cout << "Witaj " << registeredUser.getName() << "Wybierz jedna z dostepnych opcji wpisujac jej numer:\n";
	cout << "\t1. Przegladaj ksiazki\n";
	cout << "\t2. Wyszukaj ksiazke\n";
}

void userLogin(vector<User>& userDatabase)
{
	system("cls");
	cout << "Logowanie\n\n";
	string login;
	string pass;
	cout << "Login: ";
	cin >> login;
	for (auto i : userDatabase)
	{
		if (i.getName() == login)
		{
			cout << "Haslo: ";
			cin >> pass;
			while (pass != i.getPassword())
			{
				cout << "Haslo niepoprawne!\nSprobuj ponownie\n";
				system("pause");
				cout << "Logowanie\n\nLogin: " << login << "Haslo: ";
				cin >> pass;
			}
			if (i.getPassword() == pass)
			{
				cout << "Logowanie poprawne!\n";
				system("pause");
				system("cls");
				menuUser(i);
			}
		}
	}
	return;
}

void registration(vector<User>& userDatabase)
{
	system("cls");
	string login;
	cout << "Rejestracja\n\nPodaj login: ";
	cin >> login;
	bool loginAvailable = true;
	do
	{
		for (auto i : userDatabase)
		{
			if (i.getName() == login) //jezeli login zajety
			{
				loginAvailable = false; //login niedostepny
				cout << "Login zajety! wybierz inny!\n";
				system("pause");
				system("cls");
				cout << "Rejestracja\n\nPodaj login: "; //wyswietl wszystko od nowa;
				cin >> login;
				break;
			}
			loginAvailable = true; //jesli nie wybrejkowalismy sie z petli for wczesniej, to znaczy ze login ok
		}
	} while (!loginAvailable);
	string password;
	cout << "Login poprawny. \nPodaj haslo: ";
	cin >> password;
	bool goodPassword = false;
	while (!goodPassword)
	{
		if (password.size() > 8)
		{
			goodPassword = true;
			break;
		}
		else
		{
			cout << "Haslo za slabe! podaj inne\n";
			system("pause");
			system("cls");
			cout << "Rejestracja\n\nPodaj login :" << login << "\nLogin poprawny.\nPodaj haslo: "; //wyswietl wszystko od nowa;"
			cin >> password;
		}
	}
	
	cout << "Haslo silne\nTworzenie konta";
	loading();
	User newUser(login, password);
	cout << "Uzytkownik zostal utowrzony ";
	userDatabase.push_back(newUser);
	cout << " i dodany do bazy.\nDane uzytkownika:\n";
	newUser.printUser();
	system("pause");
	start(userDatabase);
}

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
			User newUser; //Uzytkownik niezalogowany ma nazwe niezalogowany
			string name = "Niezalogowany";
			newUser.setName(name);
			break;
		}
		case 4:
		{
			registration(userDatabase);
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
	User test(name, password);
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
