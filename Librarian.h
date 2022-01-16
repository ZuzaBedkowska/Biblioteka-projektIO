#include <string>
#include "Book.h"
#include "Item.h"
#include "User.h"

using namespace std;

#ifndef LIBRARIAN_H
#define LIBRARIAN_H

class Librarian {

private:
	int id;
	string name;
	string password;
	static int count;
	bool isLogged = false;

public:
	Librarian();

	Librarian(string name, string password);

	void addBorrowment(User& user, Book & book);

	void removeBorrowment(User & user, int borrowmentId);

	void removeReservation(User & user, int reservationId);

	double getUserFine(int userId);

	void addUserFine(int userId, double fine);

	void addBook(Book book);

	void removeBook(vector <Book> & books, int bookId);

	void addItem(Item item);

	void removeItem(vector <Book> & books, int bookId, int itemId);

	void addUser(User user);

	void removeUser(vector <User> & user, int userId);

	void printBooks();

	void editBook(int bookId);

	void editUser(User& user, string new_name, int new_id, string new_password, Date new_date);

	void printUsers(vector <User> & users);

	void setName(string& newName);

	void setPassword(string& newPassoword);

	void setIsLogged(bool newLogged);

	string getName();

	string getPassword();

	bool getIsLogged();
};

#endif
