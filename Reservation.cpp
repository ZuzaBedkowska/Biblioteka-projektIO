#include "Reservation.h"

//reservation - done

int Reservation::count = 0;

Reservation::Reservation()
{
	durationDays = 7;
	id = -1;
	dateOfReservation.day = 0;
	dateOfReservation.month = 0;
	dateOfReservation.year = 0;
	Reservation::count++;
}

Reservation::Reservation(Item item)
{
	Reservation::count++;
	durationDays = 7; //tydzieñ na realizacje rezerwacji
	this->id = Reservation::count;
	this->item = item;
}

Reservation::~Reservation(){} //aby ID byly unikalne, nie zmniejszamy count

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

