#include <string>
#include <vector>
#include "Item.h"

//book - done

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
	vector<Item> items;

public:
	Book();

	Book(string title, vector <string> description, vector <string> author);

	bool isAnyItemFree();

	Item getFreeItem();

	int countItems();

	int countFreeItems();

	void printBook();

	void createItem();
	
	void setTitle(string & newTitle);

	void setAuthor(vector<string> newAuthor);

	void setDescription(vector<string> newDescription);

	int getId();

	void setId(int new_id);

	string getTitle();

	vector <string> getAuthors();

	void removeAuthors();

	vector <string> getDescription();

	void removeDescription();

	vector <Item>* getAllItems();

};

#endif
