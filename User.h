#include <string>
#include <vector>
#include "Date.h"
#include "Borrowment.h"
#include "Reservation.h"
#include "Book.h"
using namespace std;

#ifndef USER_H
#define USER_H

class User {

private:
	string name = "";
	int id = -1;
	string password = "";
	double fine = 0.0;
	Date birthDate;
	static int usersCount;
	bool isLogged = false; //informacja czy uzytkownik zalogowany
	vector <Reservation> userReservations;
	vector <Borrowment> userBorrowments;

public:
	User();

	User(string name, string password, Date birthDate);

	~User();

	bool userTest(); //sprawdzenie, czy user moze wypozyczyc/rezerwowac ksiazke ksiazke

	void addReservation(Book & chosenBook);

	void removeReservation(int reservationId);

	void printBooks();

	void addBorrowment(Book book);

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

	vector <Reservation> getUserReservations();

	vector <Borrowment> getUserBorrowments();
};

#endif
