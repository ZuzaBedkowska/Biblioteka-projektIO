#include <iostream>
#include <vector>
#include "User.h"
#include "Book.h"
#include "Librarian.h"

using namespace std;

#ifndef LIBRARIANFUNCTIONS_H
#define LIBRARIANFUNCTIONS_H

void printBookDatabase(vector <Book>& bookDatabase);

void bookSearch(vector <Book>& bookDatabase);

Librarian librarianLogin(vector <Librarian> & librarianDatabase);

void librarianMenu(Librarian loggedLibrarian, vector <User>& userDatabase, vector <Book> bookDatabase);

#endif
