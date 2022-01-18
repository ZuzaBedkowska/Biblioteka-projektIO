#include "Borrowment.h"
#include <iostream>

int Borrowment::count = 0;

//borrowment - done

Borrowment::Borrowment()
{
	count++;
	durationDays = 30;

}

Borrowment::Borrowment(Item item)
{
	Borrowment::count++;
	durationDays = 30; //30 na oddanie
	dateOfBorrowment.getCurrentDate();
	this->id = Borrowment::count;
	this->item = item;
}

void Borrowment::setId(int newId)
{
	id = newId;
}

void Borrowment::setDate(Date & newDate)
{
	dateOfBorrowment.day = newDate.day;
	dateOfBorrowment.month = newDate.month;
	dateOfBorrowment.year = newDate.year;
}

void Borrowment::setDurationDays(int newDurationDays)
{
	durationDays = newDurationDays;
}

int Borrowment::getId()
{
	return id;
}

Date Borrowment::getDate()
{
	return dateOfBorrowment;
}

int Borrowment::getDurationDays()
{
	return durationDays;
}
