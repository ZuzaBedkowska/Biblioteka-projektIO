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
#include "../UserFunctions.h"
#include "../User.cpp"
#include "../Item.h"
#include "../Item.cpp"



User u_test("a", "b", { 1,1,1900 });

TEST(UserTest,IsNameOk)
{
	ASSERT_EQ("a", u_test.getName());
}

TEST(UserTest, IsPasswordOk)
{
	ASSERT_EQ("b", u_test.getPassword());
}
