#include <iostream>
#include <cstring>
#include "Book.h"

void Book::setTitle(const char* title)
{
	if (title == nullptr)
	{
		std::cout << "Invalid title!\n";
		this->title = nullptr;
		return;
	}

	int length = strlen(title) + 1;
	delete[] this->title;
	this->title = new char[length];
	for (int i = 0; i < length; i++)
	{
		this->title[i] = title[i];
	}
}

void Book::setPage(int pages)
{
	if (pages < 0)
	{
		std::cout << "Invalid pages!\n";
		pages = 0;
		return;
	}

	this->pages = pages;
}

const char* Book::getTitle() const
{
	if (this->title == nullptr)
	{
		return "No title";
	}

	return this->title;
}

int Book::getPages() const
{
	return this->pages;
}
