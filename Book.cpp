#include "Book.h"
#include <iostream>

using namespace std;

//book - done

int Book::count = 0;

Book::Book()
{
	title = "";
	count++;
	id = count;

}

Book::Book(string title, vector <string> description, vector <string> author) {
	Book::count++;
	this->id = Book::count;
	this->title = title;
	this->description = description;
	this->author = author;
}

bool Book::isAnyItemFree() {
	for (auto i : items) {
		if (i.getIsBorrowable()) return true;
	}
	return false;
}

Item Book::getFreeItem() {
	for (auto i : items) {
		if (i.getIsBorrowable()) return i;
	}
}

int Book::countItems() {
	return this->items.size();
}

void Book::printBook() {
	cout << "\"" << title << "\", ";
	if (author.size() == 1)
	{
		cout << "Autor: " << author[0] << "\n";
	}
	else 
	{
		cout << "Autorzy: ";
		for (int i = 0; i < author.size() - 1; ++i) //zeby nie wypisywac przecinka na koncu, element ostatni zostanie wypisany osobno
		{
			cout << i << ", ";
		}
		cout << author.back();
		cout << "\n";
	}
	
}

void Book::createItem() {
	this->items.push_back(Item());
}

void Book::setTitle(string & newTitle) {
	title = newTitle;
}

void Book::setAuthor(string& newAuthor) {
	author.push_back(newAuthor);
}

void Book::setDescription(string& newDescription) {
	description.push_back(newDescription);
}

int Book::getId()
{
	return id;
}

string Book::getTitle()
{
	return title;
}

vector<string> Book::getAuthors()
{
	return author;
}

vector<string> Book::getDescription()
{
	return description;
}

vector<Item>* Book::getAllItems()
{
	return &items;
}

