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
	vector <string> description;
	static int count;
	vector<string> author;

public:
	bool isAnyItemFree();

	Item getFreeItem();

	int countItems();

	void printBook();

	void createItem();
	
	void setTitle(string & newTitle);

	void setAuthor(string& newAuthor);

	void setDescription(string& newDescription);

	int getId();

	string getTitle();

	vector <string> getAuthors();

	vector <string> getDescription();
};

#endif
