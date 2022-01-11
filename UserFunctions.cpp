#include "UserFunctions.h"
#include "Reservation.h"
using namespace std;

void bookReservation(User& registeredUser, vector <Book>& bookDatabase)
{
	cout << "\nAby wypozyczyc ksiazke, wpisz W\nAby wrocic do menu, wpisz M\nTwoj wybor: ";
	char choice;
	cin >> choice;
	switch (choice)
	{
		case 'W':
		{
			cout << "Podaj numer ksiazki z listy: ";
			int bookNumber;
			cin >> bookNumber;
			while (bookNumber > bookDatabase.size() || bookNumber < 0)
			{
				cout << "Wpisano niewlasciwy numer!\nPodan numer jeszcze raz: ";
				cin >> bookNumber;
			}

			bookDatabase[bookNumber].createItem(); //robocze robienie wolnego itemu
			if (bookDatabase[bookNumber].isAnyItemFree()) {
				Reservation res = Reservation(registeredUser, bookDatabase[bookNumber].getFreeItem());
				bookDatabase[bookNumber].getFreeItem().setIsBorrowable(false);
				cout << "Pomyslnie zarejestrowano rezerwacje o id: " << res.getId();
			}
			else {
				cout << "Brak wolnego egzemplarza podanej ksiazki";
				bookReservation(registeredUser, bookDatabase);
			}

			break;
		}
		case 'M':
		{
			userMenu(registeredUser, bookDatabase);
			return;
		}
	}
}

void getLogin (string & login)
	{
	cout << "Login: ";
	cin >> login;
	}

void getPassword(string & login, string & password)
{
	cout << "Login: " << login << "\nLogin poprawny!\nHaslo: ";
	cin >> password;
}

void printBookDatabase(User & registeredUser, vector <Book>& bookDatabase)
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
	if (registeredUser.getIsLogged())
	{
		bookReservation(registeredUser, bookDatabase);
	}
	else
	{
		cout << "\nAby wypozyczyc ksiazke, musisz sie zalogowac!\n";
		system("pause");
		userMenu(registeredUser, bookDatabase);
	}
}

void bookSearch(User& registeredUser, vector <Book>& bookDatabase)
{
	system("cls");
	cout << "Wyszukiwanie ksiazki\nPodaj wyszukiwana fraze: ";
	string phrase;
	cin >> phrase;
	cout << "\nTytuly zawierajace podana fraze:\n";
	vector <Book> foundTitles;
	vector <Book> foundAuthors;
	vector <Book> allFound;
	for (auto & i : bookDatabase)
	{
		if (i.getTitle().find(phrase) < i.getTitle().size())
		{
			foundTitles.push_back(i);
			allFound.push_back(i);
		}
		for (auto & j : i.getAuthors())
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
	if (registeredUser.getIsLogged())
	{
		bookReservation(registeredUser, allFound);
	}
	else
	{
		cout << "\nAby wypozyczyc ksiazke, musisz sie zalogowac!\n";
		system("pause");
		userMenu(registeredUser, bookDatabase);
	}
}

void userMenu(User& registeredUser, vector <Book>& bookDatabase)
{
	system("cls");
	cout << "Witaj " << registeredUser.getName() << "!\nWybierz jedna z dostepnych opcji wpisujac jej numer:\n";
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
			printBookDatabase(registeredUser, bookDatabase);
			break;
		}
		case 2:
		{
			bookSearch(registeredUser, bookDatabase);
			break;
		}
		default:
		{
			cout << "Wybierz wlasciwa opcje!\n";
			system("pause");
			userMenu(registeredUser, bookDatabase);
			return;
		}
	}
}

User userLogin(vector<User>& userDatabase)
{
	system("cls");
	string login;
	string pass;
	cout << "Logowanie\n\n";
	getLogin(login); //podawanie loginu
	bool loginFound = false; //jezeli login znaleziono
	while (!loginFound) //dopoki loginu nie znaleziono
	{
		for (auto i : userDatabase) //wyszukanie loginu w bazie
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

void userRegistration(vector<User>& userDatabase)
{
	system("cls");
	string login;
	cout << "Rejestracja\n\n";
	getLogin(login);
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
				cout << "Rejestracja\n\n"; //wyswietl wszystko od nowa;
				getLogin(login);
				break;
			}
			loginAvailable = true; //jesli nie wybrejkowalismy sie z petli for wczesniej, to znaczy ze login ok
		}
	} while (!loginAvailable);
	string password;
	cout << "Login poprawny! \nPodaj haslo: ";
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
			cout << "Rejestracja\n\n";
			getPassword(login, password);
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
		cout << "\nPodaj date urodzenia wpisujac numer dnia, miesiaca i roku\nDzien: ";
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