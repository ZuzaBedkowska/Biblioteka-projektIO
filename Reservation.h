#include "Date.h"
#include "Item.h"
using namespace std;

#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {

private:
	int id;
	Date dateOfReservation;
	int durationDays;
	Item item;
	static int count;


public:

	Reservation();

	Reservation(Item item);

	void setId(int newId);

	void setDate(Date newDate);

	void setDurationDays(int newDurationDays);

	int getId();

	Date getDate();

	int getDurationDays();

	Item getItem();
};

#endif
