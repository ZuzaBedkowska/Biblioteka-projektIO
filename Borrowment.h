#include "Date.h"
#include "Item.h"
using namespace std;

//borrowment - done

#ifndef BORROWMENT_H
#define BORROWMENT_H


class Borrowment {

private:
	int id;
	Date dateOfBorrowment;
	int durationDays;
	Item item;
	static int count;

public:
	Borrowment();

	Borrowment(Item item);

	void setId(int newId);

	void setDate(Date & newDate);

	void setUserId(int newUSerId);

	void setDurationDays(int newDurationDays);

	int getId();

	Date getDate();

	int getUserId();

	int getDurationDays();
};

#endif
