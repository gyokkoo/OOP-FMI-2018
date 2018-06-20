#include <iostream>
#include <cstring>
#include "Book.h"

Book::Book() : title(nullptr), pages(0)
{
}

Book::Book(const char* title, int pages) : Book()
{
	this->setTitle(title);
	this->setPages(pages);
}

Book::Book(const Book& other) : Book()
{
	this->setTitle(other.title);
	this->setPages(other.pages);
}

Book& Book::operator=(const Book& rhs)
{
	if (this != &rhs)
	{
		this->setTitle(rhs.title);
		this->setPages(rhs.pages);
	}

	return *this;
}

Book::~Book()
{
	delete[] this->title;
}

bool Book::operator<(const Book& rhs)
{
	return strcmp(this->title, rhs.title) < 0 ? true : false;
}

bool Book::operator>(const Book & rhs)
{
	return strcmp(this->title, rhs.title) > 0 ? true : false;
}

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

void Book::setPages(int pages)
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

std::istream & operator>>(std::istream & is, Book & book)
{
	const int maxSize = 200;
	char buffer[maxSize + 1];
	int pages = 0;

	std::cout << "Enter book title: ";
	is.getline(buffer, maxSize);
	book.setTitle(buffer);

	std::cout << "Enter pages count: ";
	is >> pages;
	book.setPages(pages);

	return is;
}

std::ostream & operator<<(std::ostream & os, const Book & book)
{
	os << "Book title: " << book.getTitle() << "\n"
		<< "Total pages: " << book.getPages() << "\n";

	return os;
}
