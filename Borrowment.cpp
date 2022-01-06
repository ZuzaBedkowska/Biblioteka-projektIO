#include "Borrowment.h"

Borrowment::Borrowment()
{
	throw "Not yet implemented";
}

void Borrowment::setId(int newId)
{
	id = newId;
}

void Borrowment::setDate(Date newDate)
{
	dateOfBorrowment = newDate;
}

void Borrowment::setUserId(int newUSerId)
{
	userID = newUSerId;
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

int Borrowment::getUserId()
{
	return userID;
}

int Borrowment::getDurationDays()
{
	return durationDays;
}
