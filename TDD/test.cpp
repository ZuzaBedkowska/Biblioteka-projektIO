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
vector <User> ud_test;
vector <Item> id_test;

TEST(UserTest, DoesUserSetFineWork)
{
	EXPECT_EQ(u_test.getFine(), 0.0);
	u_test.setFine(10.0);
	EXPECT_DOUBLE_EQ(u_test.getFine(), 10.0);
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
	vector <string> authors(1, author);
	b_test.setAuthor(authors);
	b_test.setDescription(authors);
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

TEST(LibrarianTest, DoesLibrarianBookRemoveWork)
{
	for (int i = 0; i < 10; ++i)
	{
		bd_test.push_back(Book()); //sztuczna baza ksiazek
	}
	int id = bd_test[1].getId();
	int s_test = bd_test.size();
	l_test.removeBook(bd_test, 1);
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

TEST(LibrarianTest, DoesLibrarianUserRemoveWork)
{
	for (int i = 0; i < 10; ++i)
	{
		User def("name", "pass", {1, 1, 1970});
		ud_test.push_back(def); //sztuczna baza uzytkownikow
	}
	int id = ud_test[1].getId();
	int s_test = ud_test.size();
	l_test.removeUser(ud_test, 1);
	bool found = false;
	for (auto i : ud_test)
	{
		if (i.getId() == id)
		{
			found = true;
			break;
		}
	}
	EXPECT_FALSE(found);
	EXPECT_EQ(ud_test.size(), s_test - 1);
}

TEST(LibrarianTest, DoesLibrarianBookEditWork)
{
	vector <Book> bd_test;
	for (int i = 0; i < 10; ++i)
	{
		bd_test.push_back(Book());				 //sztuczna baza ksiazek
	}
	string newName = "newName";
	string autor = "NewAutor";
	string description = "NewDescription";
	vector <string> autors(1, autor);
	vector <string> descriptions(1, description);
	int newId = 10;
	l_test.editBook(bd_test[0], newName, newId, autors, descriptions);
	EXPECT_EQ(bd_test[0].getTitle(), "newName");
	EXPECT_EQ(bd_test[0].getId(), 10);
	EXPECT_EQ(bd_test[0].getAuthors(), autors);
	EXPECT_EQ(bd_test[0].getDescription(), descriptions);
}

TEST(LibrarianTest, DoesLibrarianRemoveItemWork) 
{
	for (int i = 0; i < 10; ++i)
	{
		bd_test[0].createItem(); //sztuczna baza item??w ksi????ek
	}
	id_test =( * bd_test[0].getAllItems());
	int idB = bd_test[0].getId(); //id 2 ksiazki
	int idI = id_test[1].getId(); //id 2 itemu
	int s_test = id_test.size();
	l_test.removeItem(bd_test, idB, idI);
	id_test = (* bd_test[0].getAllItems());
	bool found = false;
	for (auto i : id_test)
	{
		if (i.getId() == idI)
		{
			found = true;
			break;
		}
	}
	EXPECT_FALSE(found);
	EXPECT_EQ(id_test.size(), s_test-1);
}

TEST(LibrarianTest, DoesLibrarianAddBookWork)
{
	Book def;
	int id = def.getId();
	int s_test = bd_test.size();
	l_test.addBook(bd_test, def);
	bool found = false;
	for (auto i : bd_test)
	{
		if (i.getId() == id)
		{
			found = true;
			break;
		}
	}
	EXPECT_TRUE(found);
	EXPECT_EQ(bd_test.size(), s_test + 1);
	EXPECT_EQ(bd_test.back().getId(), id);
}

TEST(LibrarianTest, DoesLibrarianAddUserkWork)
{
	User def("name", "pass", {1,1,1970});
	int id = def.getId();
	int s_test = ud_test.size();
	l_test.addUser(ud_test, def);
	bool found = false;
	for (auto i : ud_test)
	{
		if (i.getId() == id)
		{
			found = true;
			break;
		}
	}
	EXPECT_TRUE(found);
	EXPECT_EQ(ud_test.size(), s_test + 1);
	EXPECT_EQ(ud_test.back().getId(), id);
}

TEST(LibrarianTest, DoesLibrarianAddUserFineWork)
{
	u_test.addBorrowment(bd_test[0]);
	Date date_test;
	date_test.day = 16;
	date_test.month = 12;
	date_test.year = 2021;
	u_test.getUserBorrowments()[0].setDate(date_test);
	l_test.addUserFine(u_test, 0); //za przetrzymanie funkcja wyliczy, za uszkodzenia podajemy sami
	EXPECT_DOUBLE_EQ(u_test.getFine(), 0.5);
	l_test.addUserFine(u_test, 10); //za przetrzymanie funkcja wyliczy, za uszkodzenia podajemy sami
	EXPECT_DOUBLE_EQ(u_test.getFine(), 10.5);
}

TEST(BorrowmentTest, DoesBorrowmentWork)
{
	User testUser("name", "pass", {1,1,1970});
	EXPECT_EQ(testUser.getUserBorrowments().size(), 0);
	testUser.addBorrowment(b_test);
	EXPECT_EQ(testUser.getUserBorrowments().size(), 1);
}

TEST(BorrowmentTest, DoesBorrowmentSetDateWork)
{
	User testUser("name", "pass", { 1,1,1970 });
	EXPECT_EQ(testUser.getUserBorrowments().size(), 0);
	testUser.addBorrowment(b_test);
	EXPECT_EQ(testUser.getUserBorrowments().size(), 1);

	Date date_test;
	date_test.day = 16;
	date_test.month = 12;
	date_test.year = 2021;
	testUser.getUserBorrowments()[0].setDate(date_test);
	EXPECT_EQ(testUser.getUserBorrowments()[0].getDate().day, date_test.day);
	EXPECT_EQ(testUser.getUserBorrowments()[0].getDate().month, date_test.month);
	EXPECT_EQ(testUser.getUserBorrowments()[0].getDate().year, date_test.year);
}

TEST(BookTest, DoesCountFreeItemsWork)
{
	Book testBook;
	testBook.createItem();
	testBook.createItem();
	testBook.createItem();
	testBook.createItem();
	int testFreeItems = testBook.countFreeItems();
	EXPECT_EQ(testBook.countFreeItems(), testFreeItems);
	u_test2.addReservation(testBook);
	EXPECT_EQ(testBook.countFreeItems(), testFreeItems - 1);
	u_test2.addBorrowment(testBook);
	EXPECT_EQ(testBook.countFreeItems(), testFreeItems - 2);
}