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
	bool isLogged; //informacja czy uzytkownik zalogowany

public:
	User();

	User(string name, string password, Date birthDate);

	~User();

	void addReservation(int bookId);

	void removeReservation(int reservationId);

	void printBooks();

	void addBorrowment(int bookid);

	void removeBorrowment();

	void printBorrowments();

	void printUser();

	void setName(string& newName);

	void setId(int newId);

	void setPassword(string& newPassword);

	void setFine(double newFine);

	void setBirthDate(Date newBirthDate);

	void setIsLogged(bool newLogged);

	string getName();

	int getId();

	string getPassword();

	double getFine();

	Date getBirthDate();

	static int getUsersCount() {
		return usersCount;
	}

	bool getIsLogged();
};

#endif
