#include <iostream>
#include "Library.h"

Library::Library() : capacity(DEFAULT_CAPACITY), size(0)
{
	this->books = new Book[DEFAULT_CAPACITY];
}

Library::Library(const Library& other)
{
	this->copyFrom(other);
}

Library& Library::operator=(const Library& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

Library::~Library()
{
	this->clear();
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
	this->size--;
}

void Library::removeBook(const char* title)
{
	if (title == nullptr)
	{
		std::cout << "Invalid title!\n";
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(this->books[i].getTitle(), title) == 0)
		{
			this->removeBook(i);
			return;
		}
	}

	std::cout << "Book with title " << title << " does not exist!\n";
}

void Library::sortByTitle()
{
	for (int i = 0; i < this->size - 1; i++)
	{
		for (int j = i + 1; j < this->size; j++)
		{
			if (this->books[j] < this->books[i])
			{
				Book temp = this->books[i];
				this->books[i] = this->books[j];
				this->books[j] = temp;
			}
		}
	}
}

void Library::resize(int newCapacity)
{
	this->capacity = newCapacity;
	Book* temp = this->books;
	this->books = new Book[newCapacity];
	for (int i = 0; i < this->size; i++)
	{
		this->books[i] = temp[i];
	}
	delete[] temp;
}

void Library::copyFrom(const Library& other)
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
	this->size = 0;
	this->capacity = 0;
}

std::ostream& operator<<(std::ostream& os, const Library& library)
{
	if (library.getSize() == 0)
	{
		os << "No books in the library!\n";
	}
	else
	{
		os << "All Books: \n";
		for (int i = 0; i < library.getSize(); i++)
		{
			os << library[i];
		}
	}
	
	return os;
}
