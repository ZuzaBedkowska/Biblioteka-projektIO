#include "UserFunctions.h"
using namespace std;


void userMenu(User& registeredUser)
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
				userMenu(i);
			}
		}
	}
	return;
}

void userRegistration(vector<User>& userDatabase)
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
	Date birthDate;
	cout << "Podaj date urodzenia wpisujac numer dnia, miesiaca i roku\nDzien: ";
	cin >> birthDate.day;
	cout << "Miesiac: ";
	cin >> birthDate.month;
	cout << "Rok: ";
	cin >> birthDate.year;
	while (!birthDate.isTrue())
	{
		cout << "Data niepoprawna, Podaj date jeszcze raz!\n";
		system("pause");
		system("cls");
		cout << "Rejestracja\n\nPodaj login :" << login << "\nLogin poprawny.\nPodaj haslo: "; //wyswietl wszystko od nowa;"
		for (auto i : password)
		{
			cout << "*";
		}
		cout << "Podaj date urodzenia wpisujac numer dnia, miesiaca i roku\nDzien: ";
		cin >> birthDate.day;
		cout << "Miesiac: ";
		cin >> birthDate.month;
		cout << "Rok: ";
		cin >> birthDate.year;
	}
	User newUser(login, password, birthDate);
	cout << "Uzytkownik zostal utowrzony ";
	userDatabase.push_back(newUser);
	cout << " i dodany do bazy.\nDane uzytkownika:\n";
	newUser.printUser();
	system("pause");
}