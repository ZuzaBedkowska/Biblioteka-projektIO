#include "Reservation.h"
int Reservation::count = 0;

Reservation::Reservation(Item item)
{
	Reservation::count++;
	this->id = Reservation::count;
	this->item = item;
}

void Reservation::setId(int newId)
{
	id = newId;
}

void Reservation::setDate(Date newDate)
{
	dateOfReservation = newDate;
}

void Reservation::setDurationDays(int newDurationDays)
{
	durationDays = newDurationDays;
}

int Reservation::getId()
{
	return id;
}

Date Reservation::getDate()
{
	return dateOfReservation;
}

int Reservation::getDurationDays()
{
	return durationDays;
}

Item Reservation::getItem()
{
	return item;
}
