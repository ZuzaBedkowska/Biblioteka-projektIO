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

TEST(LibrarianTest, DoesUserNameEditWork)
{
	string TestoweImie = "aaaaa";
	l_test.editUser(u_test,TestoweImie,-1,"o", d_test);
	ASSERT_EQ(u_test.getName(), "aaaaa");
}

TEST(LibrarianTest, DoesUserIDEditWork)
{
	int TestoweID = 999;
	l_test.editUser(u_test, "a", TestoweID, "o", d_test);
	ASSERT_EQ(u_test.getId(), 999);
}

TEST(LibrarianTest, DoesUserPasswordEditWork)
{
	string TestoweHaslo = "123456789";
	l_test.editUser(u_test, "a", -1, TestoweHaslo, d_test);
	ASSERT_EQ(u_test.getPassword(), TestoweHaslo);
}