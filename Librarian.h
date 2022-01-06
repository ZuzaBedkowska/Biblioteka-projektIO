#include <string>
#include "Book.h"
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

public:
	Librarian();

	void addBorrowment(int userId, int itemId);

	void removeBorrowment(int borrowmentId);

	void removeReservation(int reservationId);

	double getUserFine(int userId);

	void addUserFine(int userId, double fine);

	void addBook(Book book);

	void removeBook(int bookId);

	void addItem(Item item);

	void removeItem(int itemId);

	void addUser(User user);

	void removeUser(int userId);

	void printBooks();

	void editBook(int bookId);

	void editUser(int userID);

	void printUsers(User users[]);

	void setName(string& newName);

	void setPassword(string& newPassoword);

	string getName();

	string getPassword();
};

#endif
