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
Book b_test;
Date d_test(-1, -1, -1);
User u_test2("a", "b", { 1, 1, 1900 });
vector <Book> bd_test;


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

TEST(UserTest, DoesUserTestWork) //test jednostkowy do userTest
{
	string author = "";
	b_test.setAuthor(author);
	b_test.setDescription(author);
	b_test.setTitle(author);
	u_test.setFine(0.0);
	EXPECT_TRUE(u_test.userTest()); //0 wypozyczonych ksiazek
	b_test.createItem();
	u_test.addReservation(b_test);
	EXPECT_TRUE(u_test.userTest()); //1 wypozyczona ksiazka
	b_test.createItem();
	u_test.addReservation(b_test);
	EXPECT_TRUE(u_test.userTest()); //2
	b_test.createItem();
	u_test.addReservation(b_test);
	EXPECT_TRUE(u_test.userTest()); //3
	b_test.createItem();
	u_test.addReservation(b_test);
	EXPECT_TRUE(u_test.userTest()); //4
	b_test.createItem();
	u_test.addReservation(b_test);
	EXPECT_FALSE(u_test.userTest()); //5 i wiecej ksiazek juz nie mozna
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

TEST(LibrarianTest, DoesUserBirthDateDayEditWork)
{
	Date TestowaData(10, 2, 2010);
	l_test.editUser(u_test, "a", -1, "o", TestowaData);
	ASSERT_EQ(u_test.getBirthDate().day, TestowaData.day);
}

TEST(LibrarianTest, DoesUserBirthDateMonthEditWork)
{
	Date TestowaData(10, 2, 2010);
	l_test.editUser(u_test, "a", -1, "o", TestowaData);
	ASSERT_EQ(u_test.getBirthDate().month, TestowaData.month);
}

TEST(LibrarianTest, DoesUserBirthDateYearEditWork)
{
	Date TestowaData(10, 2, 2010);
	l_test.editUser(u_test, "a", -1, "o", TestowaData);
	ASSERT_EQ(u_test.getBirthDate().year, TestowaData.year);
}

TEST(LibrarianTest, DoesUserBirthDateEditWork)
{
	Date TestowaData(10, 2, 2010);
	l_test.editUser(u_test, "a", -1, "o", TestowaData);
	ASSERT_EQ(u_test.getBirthDate().day, TestowaData.day);
	ASSERT_EQ(u_test.getBirthDate().month, TestowaData.month);
	ASSERT_EQ(u_test.getBirthDate().year, TestowaData.year);
}

TEST(LibrarianTest, DoesLibrarianAddBorrowmentWork)
{
	b_test.createItem();
	l_test.addBorrowment(u_test, b_test);
	vector <Borrowment> borrowments_test;
	borrowments_test = u_test.getUserBorrowments();
	EXPECT_EQ(borrowments_test.size(), 1);
}

TEST(LibrarianTest, DoesLibrarianRemoveReservationWork) 
{
	vector <Reservation> r_test = u_test.getUserReservations();
	int s_test = r_test.size();
	int ID_test = r_test[0].getId();
	l_test.removeReservation(u_test, ID_test);
	r_test = u_test.getUserReservations();
	EXPECT_EQ(r_test.size(), s_test-1);
	bool found = false;
	for (auto i : r_test)
	{
		if (i.getId() == ID_test)
			found = true;
	}
	EXPECT_FALSE(found);

}

TEST(LibrarianTest, DoesLibrarianRemoveBorrowmentWork)
{
	vector <Borrowment> r_test = u_test.getUserBorrowments();
	int s_test = r_test.size();
	int ID_test = r_test[0].getId();
	l_test.removeBorrowment(u_test, ID_test);
	r_test = u_test.getUserBorrowments();
	EXPECT_EQ(r_test.size(), s_test - 1);
	bool found = false;
	for (auto i : r_test)
	{
		if (i.getId() == ID_test)
			found = true;
	}
	EXPECT_FALSE(found);
}

TEST(LibrarianTest, DoesLibrarianBookEditWork)
{
	for (int i = 0; i < 10; ++i)
	{
		bd_test.push_back(Book()); //sztuczna baza ksiazek
	}
	string newName = "newName";
	string autor = "NewAutor";
	string description = "NewDescription";
	vector <string> autors(1, autor);
	vector <string> descriptions(1, description);
	int newId = 10;
	//l_test.editBook(bd_test[0], newName, newId, autors, descriptions);
	EXPECT_EQ(bd_test[0].getTitle(), "newName");
	EXPECT_EQ(bd_test[0].getId(), 10);
	EXPECT_EQ(bd_test[0].getAuthors(), autors);
	EXPECT_EQ(bd_test[0].getDescription(), descriptions);
}

TEST(LibrarianTest, DoesLibrarianBookRemoveWork)
{
	for (int i = 0; i < 10; ++i)
	{
		bd_test.push_back(Book()); //sztuczna baza ksiazek
	}
	int id = bd_test[1].getId();
	int s_test = bd_test.size();
	l_test.removeBook(bd_test, id);
	bool found = false;
	for (auto i : bd_test)
	{
		if (i.getId() == id)
		{
			found = true;
			break;
		}
	}
	EXPECT_FALSE(found);
	EXPECT_EQ(bd_test.size(), s_test - 1);
}

