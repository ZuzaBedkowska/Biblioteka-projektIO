#include "Book.h"
#include <iostream>

using namespace std;

bool Book::isAnyItemFree() {
	// TODO - implement Book::isAnyItemFree
	throw "Not yet implemented";
}

Item Book::getFreeItem() {
	// TODO - implement Book::getFreeItem
	throw "Not yet implemented";
}

int Book::countItems() {
	// TODO - implement Book::countItems
	throw "Not yet implemented";
}

void Book::printBook() {
	cout << "\"" << title << "\" ";
	for (auto i : author)
	{
		cout << i << ", ";
	}
	cout << "\n";
}

void Book::createItem() {
	// TODO - implement Book::createItem
	throw "Not yet implemented";
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
