#include "User.h"
#include "Book.h"

#include <iostream>
using namespace std;

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
	usersCount--;
}

bool User::userTest()
{
	if (((int)userReservations.size() + (int)userBorrowments.size() - 1) > 5)
	{
		return false;
	}
	else if (fine > 0)
	{
		return false;
	}
	return true;
}

void User::addReservation(Book chosenBook) {
		Reservation res = Reservation(chosenBook.getFreeItem());
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

void User::printBooks() {
	cout << "Rezerwacje:\n";
	if (userReservations.size() > 0)
	{
		for (auto i : userReservations)
		{
			cout << "\t-";
			//i.getItem().printBook();
			cout <<	"\n";
		}
	}
	else
	{
		cout << "Brak\n";
	}
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

void User::addBorrowment(int bookid) {
	// TODO - implement User::addBorrowment
	throw "Not yet implemented";
}

void User::removeBorrowment() {
	// TODO - implement User::removeBorrowment
	throw "Not yet implemented";
}

void User::printBorrowments() {
	// TODO - implement User::printBorrowments
	throw "Not yet implemented";
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
