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
Book b_test;


TEST(UserTest, DoesUserSetFineWork)
{
	EXPECT_EQ(u_test.getFine(), 0.0);
	u_test.setFine(10.0);
	EXPECT_EQ(u_test.getFine(), 10.0);
}
TEST(UserTest,IsNameOk)
{
	ASSERT_EQ("a", u_test.getName());
}

TEST(UserTest, IsPasswordOk)
{
	ASSERT_EQ("b", u_test.getPassword());
}

TEST(UserTest, isUserTestWorking) //test jednostkowy do userTest
{
	string author = "";
	b_test.setAuthor(author);
	b_test.setDescription(author);
	b_test.setTitle(author);
	u_test.setFine(0.0);
	EXPECT_EQ(u_test.getReservationCount(), 0);
	EXPECT_TRUE(u_test.userTest()); //0 wypozyczonych ksiazek
	//u_test.addReservation(b_test);
	//EXPECT_TRUE(u_test.userTest()); //1 wypozyczona ksiazka
	//u_test.addReservation(b_test);
	//EXPECT_TRUE(u_test.userTest()); //2
	//u_test.addReservation(b_test);
	//EXPECT_TRUE(u_test.userTest()); //3
	//u_test.addReservation(b_test);
	//EXPECT_TRUE(u_test.userTest()); //4
	//u_test.addReservation(b_test);
	//EXPECT_EQ(u_test.userTest(), false); // 5, juz wiecej nie mozna
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