#include <string>
#include "Date.h"
using namespace std;

#ifndef USER_H
#define USER_H

class User {

private:
	/**
	 * Imiê i nazwisko u¿ytkownika
	 */
	string name;
	int id;
	string password;
	double fine;
	Date birthDate;
	static int usersCount;

public:
	User();

	void addReservation(int bookId);

	void removeReservation(int reservationId);

	void printBooks();

	void addBorrowment(int bookid);

	void removeBorrowment();

	void printBorrowments();

	void setName(string& newName);

	void setId(int newId);

	void setPassword(string& newPassword);

	void setFine(double newFine);

	void setBirthDate(Date newBirthDate);

	string getName();

	int getId();

	string getPassword();

	double getFine();

	Date getBirthDate();

};

#endif
