#include "Librarian.h"
#include <iostream>

int Librarian::count = 0;

Librarian::Librarian()
{
	id = 0;
	count++;
}

Librarian::Librarian(string name = "name", string password = "pass")
{
	Librarian::count++;
	this->name = name;
	this->password = password;
	this->id = count;
}

void Librarian::addBorrowment(User & user,	Book & book) 
{
	user.addBorrowment(book);
}

void Librarian::removeBorrowment(User & user, int borrowmentId) {
	user.removeBorrowment(borrowmentId);
}

void Librarian::removeReservation(User & user, int reservationId) {
	user.removeReservation(reservationId);
}

double Librarian::getUserFine(int userId) {
	// TODO - implement Librarian::getUserFine
	throw "Not yet implemented";
}

void Librarian::addUserFine(int userId, double fine) {
	// TODO - implement Librarian::addUserFine
	throw "Not yet implemented";
}

void Librarian::addBook(Book book) {
	// TODO - implement Librarian::addBook
	throw "Not yet implemented";
}

void Librarian::removeBook(vector <Book> & books, int bookId) {
	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i].getId() == bookId)
		{
			books.erase(books.begin() + i);
			break;
		}
	}
}

void Librarian::addItem(Item item) {
	// TODO - implement Librarian::addItem
	throw "Not yet implemented";
}

void Librarian::removeItem(vector <Book>& books, int bookId, int itemId) {
	for (auto &i : books)
	{
		if (i.getId() == bookId)
		{	
			int licz = 0;
			for (auto &j : (*i.getAllItems()))
			{
				if (j.getId() == itemId)
				{
					cout << "found\n";
					(* i.getAllItems()).erase((* i.getAllItems()).begin() + licz);
					break;
				}
				licz++;
			}
		}
	}
}

void Librarian::addUser(User user) {
	// TODO - implement Librarian::addUser
	throw "Not yet implemented";
}

void Librarian::removeUser(vector <User> & users, int userId) {
	for (int i = 0; i < users.size(); ++i)
	{
		if (users[i].getId() == userId)
		{
			users.erase(users.begin() + i);
			break;
		}
	}
}

void Librarian::printBooks() {
	// TODO - implement Librarian::printBooks
	throw "Not yet implemented";
}

void Librarian::editBook(int bookId) {
	// TODO - implement Librarian::editBook
	throw "Not yet implemented";
}

void Librarian::editUser(User& user, string new_name, int new_id, string new_password, Date new_date) 
{
	if (new_name.size() >= 3)
	{
		user.setName(new_name);
	}

	if (new_id>0) user.setId(new_id);

	if (new_password.size() >= 8)
	{
		user.setPassword(new_password);
	}

	if (new_date.year >= 1900 && new_date.year < 2022)
	{
		if (new_date.month == 2)
		{
			if (new_date.day > 0 && new_date.day < 30) user.setBirthDate(new_date);
		}
		if ((new_date.month == 1 || new_date.month > 2) && new_date.month < 13)
		{
			if (new_date.day > 0 && new_date.day < 32) user.setBirthDate(new_date);
		}
	}

}

void Librarian::printUsers(User users[]) {
	// TODO - implement Librarian::printUsers
	throw "Not yet implemented";
}

void Librarian::setName(string& newName)
{
	name = newName;
}

void Librarian::setPassword(string& newPassoword)
{
	password = newPassoword;
}

void Librarian::setIsLogged(bool newLogged)
{
	isLogged = newLogged;
}

string Librarian::getName()
{
	return name;
}

string Librarian::getPassword()
{
	return password;
}

bool Librarian::getIsLogged()
{
	return isLogged;
}
