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
	User loggedUser;
	Librarian loggedLibrarian;
public:
	MainController(vector <User> userDatabase, vector <Librarian> librarianDatabase, vector <Book> bookDatabase);
	void start();
	void bookReservation();
	void getLogin(string& login);
	void getPassword(string& login, string& password);
	void printBookDatabase();
	void bookSearch();
	void userMenu();
	User userLogin();
	void userRegistration();
	Librarian librarianLogin();
	void librarianMenu();
	void editBook();
	void editUser();
	void addUser();
	void bookBorrowment();
	void bookReturn();
};

#endif
