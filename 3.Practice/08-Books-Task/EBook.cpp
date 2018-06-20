#include <iostream>
#include "EBook.h"

EBook::EBook() : Book::Book(), bytes(0), openedCounter(0)
{
}

EBook::EBook(const char * title, int pages, int bytes, int openedCounter) : Book::Book(title, pages)
{
	this->setBytes(bytes);
	this->setOpenedCounter(openedCounter);
}

double EBook::getRating() const
{
	if (this->openedCounter > 200)
	{
		return 5;
	}

	return this->openedCounter / 40.0;
}

void EBook::setBytes(int bytes)
{
	if (bytes < 0)
	{
		std::cout << "Invalid bytes!\n";
		return;
	}

	this->bytes = bytes;
}

void EBook::setOpenedCounter(int count)
{
	if (count < 0)
	{
		std::cout << "Invalid count!\n";
		return;
	}

	this->openedCounter = count;
}

int EBook::getBookBytes() const
{
	return this->bytes;
}

int EBook::getOpenedCount() const
{
	return this->openedCounter;
}

std::istream& operator>>(std::istream & is, EBook & book)
{
	int temp = 0;
	is >> (Book&)book;
	
	std::cout << "Enter bytes: ";
	is >> temp;
	book.setBytes(temp);
	
	std::cout << "Enter opened count: ";
	is >> temp;
	book.setOpenedCounter(temp);

	return is;
}

std::ostream& operator<<(std::ostream & os, const EBook & book)
{
	os << (const Book&)book
		<< "Bytes: " << book.getBookBytes() << "\n"
		<< "Opened: " << book.getOpenedCount() << " times\n";

	return os;
}
