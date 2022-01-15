#ifndef DATE_H
#define DATE_H

struct Date
{
	int day;
	int month;
	int year;

	bool isTrue();

	void printDate();

	void getCurrentDate();
};

#endif
