#include "Date.h"
#include "User.h"
#include "Item.h"
using namespace std;

#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {

private:
	int id;
	Date dateOfReservation;
	int durationDays;
	User user;
	Item item;
	static int count;
public:
	Reservation(User user, Item item);

	void setId(int newId);

	void setDate(Date newDate);

	void setDurationDays(int newDurationDays);

	int getId();

	Date getDate();

	int getDurationDays();
};

#endif
