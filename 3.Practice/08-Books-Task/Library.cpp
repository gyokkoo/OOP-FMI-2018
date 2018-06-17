#include <iostream>
#include "Library.h"

Library::Library() : capacity(DEFAULT_CAPACITY), size(0)
{
	this->books = new Book[DEFAULT_CAPACITY];
}

Book Library::operator[](int index) const
{
	if (index < 0 || index >= this->size)
	{
		return Book();
	}

	return this->books[index];
}

int Library::getSize() const
{
	return this->size;
}

void Library::addBook(const Book& book)
{
	if (this->size >= this->capacity)
	{
		this->resize(this->capacity * 2);
	}

	this->books[this->size] = book;
	this->size++;
}

void Library::removeBook(int index)
{
	if (index < 0 || index >= this->size)
	{
		std::cout << "Invalid index!\n";
		return;
	}

	for (int i = index; i < this->size - 1; i++)
	{
		this->books[i] = this->books[i + 1];
	}
}

void Library::resize(int newCapacity)
{
	this->capacity = newCapacity;
	Book* temp = this->books;

	delete[] this->books;
	this->books = new Book[newCapacity];

	for (int i = 0; i < this->size; i++)
	{
		this->books[i] = temp[i];
	}
}

void Library::copyFrom(const Library & other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->books = new Book[other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		this->books[i] = other.books[i];
	}
}

void Library::clear()
{
	delete[] this->books;
	this->books = nullptr;
}

std::ostream & operator<<(std::ostream & os, const Library & library)
{
	for (int i = 0; i < library.getSize(); i++)
	{
		os << library[i];
	}

	return os;
}
