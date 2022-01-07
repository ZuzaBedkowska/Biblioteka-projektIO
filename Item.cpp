#include "Item.h"

int Item::count = 0;

Item::Item() {
	Item::count++;
	this->id = Item::count;
	this->isBorrowable = true;
}

void Item::setId(int newId)
{
	id = newId;
}

void Item::setIsBorrowable(bool newIsBorrowable)
{
	isBorrowable = newIsBorrowable;
}

int Item::getId()
{
	return id;
}

bool Item::getIsBorrowable()
{
	return isBorrowable;
}
