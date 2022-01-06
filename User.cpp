#include "User.h"

User::User()
{
	//usersCount++;
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
