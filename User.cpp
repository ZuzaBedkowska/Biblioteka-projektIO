#include "User.h"
#include "Book.h"
#include <iostream>
using namespace std;

//User - done

int User::usersCount = 0;

User::User()
{
	usersCount++;
}

User::User(string name = "name", string password = "pass", Date birthDate = {1, 1, 1970})
{
	User::usersCount++;
	this->name = name;
	this->id = usersCount;
	this->password = password;
	this->fine = 0;
	this->birthDate = birthDate;
}

User::~User()
{
	userBorrowments.erase(userBorrowments.begin(), userBorrowments.end());
	userReservations.erase(userReservations.begin(), userReservations.end());
}

bool User::userTest()
{
	if (((int)userReservations.size() + (int)userBorrowments.size()) >= 5)
	{
		return false;
	}
	else if (fine > 0)
	{
		return false;
	}
	return true;
}

void User::addReservation(Book & chosenBook) {
		Reservation res = Reservation(chosenBook.getFreeItem());
		res.setId(res.getCount() + 2022000);
		chosenBook.getFreeItem().setIsBorrowable(false);
		cout << "Pomyslnie zarejestrowano rezerwacje o id: " << res.getId() << "\n";
		userReservations.push_back(res);
}

void User::removeReservation(int reservationId) {
	for (int i = 0; i < userReservations.size(); ++i)
	{
		if (userReservations[i].getId() == reservationId)
		{
			userReservations.erase(userReservations.begin() + i);
			break;
		}
	}
}

void User::addBorrowment(Book & book) {
	Borrowment bor = Borrowment(book.getFreeItem());
	bor.setId(bor.getId() + 4044000);
	book.getFreeItem().setIsBorrowable(false);
	cout << "Pomyslnie zarejestrowano rezerwacje o id: " << bor.getId() << "\n";
	userBorrowments.push_back(bor);
}

void User::removeBorrowment(int borrowmentId) {
	for (int i = 0; i < userBorrowments.size(); ++i)
	{
		if (userBorrowments[i].getId() == borrowmentId)
		{
			userBorrowments.erase(userBorrowments.begin() + i);
			break;
		}
	}
	cout << "Udalo sie zwrocic ksiazke.\n";
}

void User::printBorrowments() {
	cout << "Wypozyczenia:\n";
	if (userBorrowments.size() > 0)
	{
		for (auto i : userBorrowments)
		{
			cout << "\t-\n"; //trzeba ogarn¹æ jak wypisywaæ zarezerwowane tytu³y ksi¹¿ek
		}
	}
	else
	{
		cout << "Brak\n";
	}
}

void User::printUser()
{
	cout << "Uzytkownik nr " << id << "\n\tImie i nazwisko: " << name << "\n\tData urodzenia: ";
	birthDate.printDate();
	cout << "\tKara nalozona na uzytkownika: " << fine << "\n";
}

void User::setName(string& newName)
{
	name = newName;
}

void User::setId(int newId)
{
	id = newId;
}

void User::setPassword(string& newPassword)
{
	password = newPassword;
}

void User::setFine(double newFine)
{
	fine = newFine;
}

void User::setBirthDate(Date newBirthDate)
{
	birthDate = newBirthDate;
}

void User::setIsLogged(bool newLogged)
{
	isLogged = newLogged;
}

string User::getName()
{
	return name;
}

int User::getId()
{
	return id;
}

string User::getPassword()
{
	return password;
}

double User::getFine()
{
	return fine;
}

Date User::getBirthDate()
{
	return birthDate;
}

bool User::getIsLogged()
{
	return isLogged;
}

vector<Reservation> User::getUserReservations()
{
	return userReservations;
}

vector<Borrowment> & User::getUserBorrowments()
{
	return userBorrowments;
}
