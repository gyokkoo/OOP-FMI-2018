#pragma once
#include "Book.h"

const int DEFAULT_CAPACITY = 2;

class Library
{
public:
	Library();

	Book operator[](int index) const;
	int getSize() const;

	void addBook(const Book& book);
	void removeBook(int index);
private:
	void resize(int newCapacity);
	void copyFrom(const Library& other);
	void clear();
private:
	int size;
	int capacity;
	Book* books;
};

std::ostream& operator<<(std::ostream& os, const Library& library);