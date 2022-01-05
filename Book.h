#ifndef BOOK_H
#define BOOK_H

class Book {

private:
	int id;
	string title;
	string description;
	static int count;
	std::vector<string> author;

public:
	boolean isAnyItemFree();

	Item getFreeItem();

	int countItems();

	void printBook();

	void createItem();
};

#endif
