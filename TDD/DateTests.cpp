#include "gtest/gtest.h"
#include "pch.h"
#include "../Date.h"

Date testDate;
Date actualDate;

TEST(DateTest, DoesDateIsTrueWork) //test jednostkowy do Date is True
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
TEST(DateTest, DoesGetCurrentDateWork)
{
	testDate.day = 18;
	testDate.month = 1;
	testDate.year = 2022;
	actualDate.getCurrentDate();
	EXPECT_EQ(actualDate.day, testDate.day);
	EXPECT_EQ(actualDate.month, testDate.month);
	EXPECT_EQ(actualDate.year, testDate.year);
}

TEST(DateTest, DoesCountDifferenceWork)
{
	Date d1(1, 1, 2022);
	Date d2(10, 1, 2022);
	EXPECT_EQ(d1.countDifference(d2), 9);
	d1.day = 1;
	d2.day = 2;
	EXPECT_EQ(d1.countDifference(d2), 1);
	Date d3(1, 1, 2020);
	Date d4(1, 1, 2021);
	EXPECT_EQ(d3.countDifference(d4), 366);
}