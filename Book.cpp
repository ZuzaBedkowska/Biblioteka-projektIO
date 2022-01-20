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

Item & Book::getFreeItem() {
	for (auto &i : items) {
		if (i.getIsBorrowable()) return i;
	}
}

int Book::countItems() {
	return this->items.size();
}

int Book::countFreeItems()
{
	int free = 0;
	for (auto i : items)
	{
		if (i.getIsBorrowable())
			free++;
	}
	return free;
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
			cout << author[i] << ", ";
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

void Book::setAuthor(vector<string> newAuthor) {
	author = newAuthor;
}

void Book::setDescription(vector<string> newDescription) {
	description = newDescription;
}

int Book::getId()
{
	return id;
}

void Book::setId(int new_id)
{
	id = new_id;
}

string Book::getTitle()
{
	return title;
}

vector<string> Book::getAuthors()
{
	return author;
}

void Book::removeAuthors()
{
	for (int i = 0; i < getAuthors().size(); i++)
	{
		author.pop_back();
	}
}

vector<string> Book::getDescription()
{
	return description;
}

void Book::removeDescription()
{
	for (int i = 0; i < getDescription().size(); i++)
	{
		description.pop_back();
	}
}

vector<Item>* Book::getAllItems()
{
	return &items;
}
