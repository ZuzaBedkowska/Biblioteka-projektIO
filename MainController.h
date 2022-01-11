#include <string>
#include "Book.h"
#include "User.h"
#include "Librarian.h"
#include "Reservation.h"

using namespace std;

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

class MainController {

private:
	vector <User> userDatabase;
	vector <Librarian> librarianDatabase;
	vector <Book> bookDatabase;
	vector <Reservation> reservationDatabase;
	User loggedUser;
public:
	MainController(vector <User> userDatabase, vector <Librarian> librarianDatabase, vector <Book> bookDatabase, vector <Reservation> reservationDatabase);
	void start();
	void bookReservation();
	void getLogin(string& login);
	void getPassword(string& login, string& password);
	void printBookDatabase();
	void bookSearch();
	void userMenu();
	User userLogin();
	void userRegistration();
};

#endif
