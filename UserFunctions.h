#include <iostream>
#include <vector>
#include "User.h"
#include "Book.h"

using namespace std;

#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

void getLogin(string& login);

void getPassword(string& login, string& password);

void printBookDatabase(User& registeredUser, vector <Book>& bookDatabase);

void bookSearch(vector <Book>& bookDatabase);

void userMenu(User& registeredUser, vector <Book>& bookDatabase);

User userLogin(vector <User>& userDatabase);

void userRegistration(vector<User>& userDatabase);

#endif
