#pragma once
#include "Book.h"

const int DEFAULT_CAPACITY = 2;

class Library
{
public:
	Library();
	Library(const Library& other);
	Library& operator=(const Library& rhs);
	~Library();

	Book operator[](int index) const;
	int getSize() const;

	void addBook(const Book& book);
	void removeBook(int index);
	void removeBook(const char* name);

	void sortByTitle();
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