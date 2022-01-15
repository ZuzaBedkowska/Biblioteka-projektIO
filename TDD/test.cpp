#include "pch.h"
#include "../Book.h"
#include "../Book.cpp"
#include "../Borrowment.h"
#include "../Borrowment.cpp"
#include "../Date.h"
#include "../Date.cpp"
#include "../Reservation.h"
#include "../Reservation.cpp"
#include "../User.h"
#include "../Librarian.h"
#include "../Librarian.cpp"
#include "../UserFunctions.h"
#include "../User.cpp"
#include "../Item.h"
#include "../Item.cpp"



User u_test("a", "b", { 1,1,1900 });
Librarian l_test("admin", "ad");
Date d_test(-1, -1, -1);

TEST(UserTest,IsNameOk)
{
	ASSERT_EQ("a", u_test.getName());
}

TEST(UserTest, IsPasswordOk)
{
	ASSERT_EQ("b", u_test.getPassword());
}

TEST(LibrarianTest, DoesUserNameEditWork)		//1 - name, 2 - id, 3 - password, 4 - birth date
{
	string a = "aaa";
	l_test.editUser(u_test,a,-1,-1,d_test);
	ASSERT_EQ(u_test.getName(), "aaa");
}

