#include "pch.h"
#include "gtest/gtest.h"
#include "../Book.h"
#include "../Date.h"
#include "../Reservation.h"
#include "../User.h"
#include "../Item.h"

/*
TEST(checkUserTest, UserTest) //test jednostkowy do userTest
{
	User u_test("a", "b", { 1,1,1900 });
	Date d_test(-1, -1, -1);
	Book b_test;
	EXPECT_EQ(u_test.userTest(), true); //0 wypozyczonych ksiazek
	u_test.addReservation(b_test);
	//EXPECT_EQ(u_test.userTest(), true); //1 wypozyczona ksiazka
	/*u_test.addReservation(b_test);
	EXPECT_EQ(u_test.userTest(), true);
	u_test.addReservation(b_test);
	EXPECT_EQ(u_test.userTest(), true);
	u_test.addReservation(b_test);
	EXPECT_EQ(u_test.userTest(), true);
	u_test.addReservation(b_test);
	EXPECT_EQ(u_test.userTest(), false);
}
*/