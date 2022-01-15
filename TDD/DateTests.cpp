#include "gtest/gtest.h"
#include "pch.h"
#include "../Date.h"

Date testDate;
Date today;
TEST(checkDate, DateisTrue) //test jednostkowy do Date is True
{
	testDate.day = 29;
	testDate.month = 2;
	testDate.year = 2001;
	EXPECT_EQ(testDate.isTrue(), false);
	testDate.day = 29;
	testDate.month = 2;
	testDate.year = 2004;
	EXPECT_EQ(testDate.isTrue(), true);
	testDate.day = 33;
	testDate.month = 7;
	testDate.year = 2001;
	EXPECT_EQ(testDate.isTrue(), false);
	testDate.day = 31;
	testDate.month = 7;
	testDate.year = 2001;
	EXPECT_EQ(testDate.isTrue(), true);
	testDate.day = 31;
	testDate.month = 4;
	testDate.year = 2001;
	EXPECT_EQ(testDate.isTrue(), false);
}

TEST(currentDate, getCurrentDate)
{
	testDate.day = 15;
	testDate.month = 1;
	testDate.year = 2022;
	today.getCurrentDate();
	EXPECT_EQ(today.day, testDate.day);
	EXPECT_EQ(today.month, testDate.month);
	EXPECT_EQ(today.year, testDate.year);
}