#include "Reservation.h"

Reservation::Reservation()
{
	throw "Not yet implemented";
}

void Reservation::setId(int newId)
{
	id = newId;
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
