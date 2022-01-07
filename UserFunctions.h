#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

void userMenu(User& registeredUser);

void userLogin(vector <User>& userDatabase);

void userRegistration(vector<User>& userDatabase);

#endif
