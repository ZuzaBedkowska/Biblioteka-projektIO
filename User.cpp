#include "User.h"
#include <iostream>
using namespace std;

int User::usersCount = 0;

User::User(string name = "name", string password = "pass", Date birthDate = {1, 1, 1970})
{
	User::usersCount++;
	this->name = name;
	this->id = usersCount;
	this->password = password;
	this->fine = 0;
	this->birthDate = birthDate;
}

void User::addReservation(int bookId) {
	// TODO - implement User::addReservation
	throw "Not yet implemented";
}

void User::removeReservation(int reservationId) {
	// TODO - implement User::removeReservation
	throw "Not yet implemented";
}

void User::printBooks() {
	// TODO - implement User::printBooks
	throw "Not yet implemented";
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
	cout << "Uzytkownik nr " << id << "\n\tImie i nazwisko: " << name << "\n Data urodzenia: ";
	birthDate.printDate();
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
