#include <string>
#include <vector>
#include "Item.h"


using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book {

private:
	int id;
	string title;
	string description;
	static int count;
	vector<string> author;

public:
	bool isAnyItemFree();

	Item getFreeItem();

	int countItems();

	void printBook();

	void createItem();
};

#endif
