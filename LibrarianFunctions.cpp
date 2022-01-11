#include "LibrarianFunctions.h"
#include "UserFunctions.h"
using namespace std;

void printBookDatabase(vector <Book>& bookDatabase)
{
	system("cls");
	cout << "Baza Ksiazek:\n";
	int number = 1;
	for (auto i : bookDatabase)
	{
		cout << number << ". ";
		i.printBook();
		number++;
	}
}

void bookSearch(vector <Book>& bookDatabase)
{
	system("cls");
	cout << "Wyszukiwanie ksiazki\nPodaj wyszukiwana fraze: ";
	string phrase;
	cin >> phrase;
	cout << "\nTytuly zawierajace podana fraze:\n";
	vector <Book> foundTitles;
	vector <Book> foundAuthors;
	vector <Book> allFound;
	for (auto& i : bookDatabase)
	{
		if (i.getTitle().find(phrase) < i.getTitle().size())
		{
			foundTitles.push_back(i);
			allFound.push_back(i);
		}
		for (auto& j : i.getAuthors())
		{
			if (j.find(phrase) < j.size())
			{
				foundAuthors.push_back(i);
				allFound.push_back(i);
				break;
			}
		}
	}
	int number = 1;
	if (foundTitles.size() == 0)
	{
		cout << "Brak\n";
	}
	else
	{
		for (auto i : foundTitles)
		{
			cout << number << ". ";
			i.printBook();
			number++;
		}
	}
	cout << "\nNazwiska autorow zawierajace podana fraze:\n";
	if (foundAuthors.size() == 0)
	{
		cout << "Brak\n";
	}
	else
	{
		for (auto i : foundAuthors)
		{
			cout << number << ". ";
			i.printBook();
			number++;
		}
	}
}

Librarian librarianLogin(vector <Librarian>& librarianDatabase)
{
	system("cls");
	string login;
	string pass;
	cout << "Logowanie\n\n";
	getLogin(login); //podawanie loginu
	bool loginFound = false; //jezeli login znaleziono
	while (!loginFound) //dopoki loginu nie znaleziono
	{
		for (auto i : librarianDatabase) //wyszukanie loginu w bazie
		{
			if (i.getName() == login) //jezeli login znaleziony
			{
				loginFound = true;
				cout << "Login poprawny! \nHaslo: ";
				cin >> pass;
				while (pass != i.getPassword())
				{
					cout << "Haslo niepoprawne!\nSprobuj ponownie\n";
					system("pause");
					system("cls");
					cout << "Logowanie\n\n";
					getPassword(login, pass);
				}
				if (i.getPassword() == pass)
				{
					cout << "Logowanie poprawne!\n";
					system("pause");
					system("cls");
					return i;
				}
			}
			else
			{
				cout << "Login niepoprawny! Sprobuj ponownie\n";
				system("pause");
				system("cls");
				cout << "Logowanie\n\n";
				getLogin(login);
			}
		}
	}
}

void librarianMenu(Librarian loggedLibrarian, vector <User>& userDatabase, vector <Book> bookDatabase)
{
	system("cls");
	cout << "Witaj " << loggedLibrarian.getName() << "!\nWybierz jedna z dostepnych opcji wpisujac jej numer:\n";
	cout << "\t1. Przegladaj ksiazki\n";
	cout << "\t2. Wyszukaj ksiazke\n";
	//cout << "\t3. Wróæ do logowania\n"; jeœli ktoœ umie to zrobiæ bez przekazywania wszêdzie listy uzytkownikow to zapraszam
	cout << "Twoj wybor: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		printBookDatabase(bookDatabase);
		break;
	}
	case 2:
	{
		bookSearch(bookDatabase);
		break;
	}
	default:
	{
		cout << "Wybierz wlasciwa opcje!\n";
		system("pause");
		librarianMenu(loggedLibrarian, userDatabase, bookDatabase);
		return;
	}
	}
}

