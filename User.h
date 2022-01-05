#include <string>
using namespace std;

#ifndef USER_H
#define USER_H

struct Date
	{
	int day;
	int month;
	int year;
	};

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
	void addReservation(int bookId);

	void removeReservation(int reservationId);

	void printBooks();

	void addBorrowment(int bookid);

	void removeBorrowment();

	void printBorrowments();
};

#endif
