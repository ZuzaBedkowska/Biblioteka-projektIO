#include "Item.h"

Item::Item() {
	// TODO - implement Item::Item
	throw "Not yet implemented";
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
