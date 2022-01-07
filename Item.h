#ifndef ITEM_H
#define ITEM_H

class Item {

private:
	int id;
	bool isBorrowable;
	static int count;

public:
	Item();

	void setId(int newId);

	void setIsBorrowable(bool newBorrowable);

	int getId();

	bool getIsBorrowable();
};

#endif
