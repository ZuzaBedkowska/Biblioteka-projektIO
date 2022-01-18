#include <ctime>

#ifndef DATE_H
#define DATE_H

struct Date
{
	int day = 1;
	int month = 1;
	int year = 1970;

	Date();
	Date(int dayn, int monthn, int yearn);
	bool isTrue();
	void printDate();
	void getCurrentDate();
	int countLeapYears();
	int countDifference(Date dt2);
};

#endif
