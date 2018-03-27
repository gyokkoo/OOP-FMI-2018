#include <iostream>
#include "List.h"

List::List() : size(0), capacity(INITIAL_CAPACITY)
{
	this->arr = new int[INITIAL_CAPACITY];
}

List::List(int capacity) : size(0)
{
	this->capacity = capacity;
	this->arr = new int[capacity];
}

List::List(const List& list)
{
	this->size = list.size;
	this->capacity = list.capacity;
	this->arr = new int[list.capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = list.arr[i];
	}
}

List::~List()
{
	delete[] this->arr;
}

void List::resize(int capacity)
{
	if (capacity < 0)
	{
		std::cout << "Error! Cannot resize negative size.\n";
		return;
	}

	if (capacity < this->capacity)
	{
		std::cout << "Warning! Resizing array... data may be lost.\n";
		this->size = capacity - 1;
	}

	// Save the current pointer, create new *array with new capacity, copy elements
	// then delete the old pointer
	int* temp = this->arr;
	this->arr = new int[capacity];
	this->capacity = capacity;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = temp[i];
	}

	delete[] temp;
	std::cout << "Array was resized, new capacity: " << this->capacity << "\n";
}

void List::insertAt(int i, int value)
{
	if (i < 0 || i >= this->size)
	{
		std::cout << "Error! Array index out of bounds.\n" ;
		return;
	}

	if (this->size >= this->capacity - 1)
	{
		resize(this->capacity * 2);
	}

	this->size++;
	this->shiftRight(i);
	this->arr[i] = value;
}

void List::pushBack(int value)
{
	if (this->size >= this->capacity)
	{
		resize(this->capacity * 2);
	}

	this->size++;
	this->arr[this->size - 1] = value;
}

int List::popBack()
{
	if (this->size <= 0)
	{
		std::cout << "Error! Cannot pop empty array. Return -1\n";
		return -1;
	}

	this->size--;
	return this->arr[this->size - 1];
}

void List::removeAt(int i)
{
	if (i < 0 || i >= this->size)
	{
		std::cout << "Error! Array index out of bounds.\n";
		return;
	}

	shiftLeft(i);
	this->size--;
}

void List::clear()
{
	delete[] this->arr;
	this->arr = nullptr;
	this->size = 0;
	this->capacity = INITIAL_CAPACITY;
	std::cout << "Array cleared!\n";
}

bool List::isEmpty() const
{
	return this->size == 0;
}

int List::getAt(int i) const
{
	if (i < 0 || i >= this->size)
	{
		std::cout << "Error! Array index out of bounds. Return -1.\n";
		return -1;
	}

	return this->arr[i];
}

int List::getCapacity() const
{
	return this->capacity;
}

int List::getSize() const
{
	return this->size;
}

void List::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << " ";
	}
	std::cout << "\n";
}

// Shift the array with one position left from given index
void List::shiftLeft(int index)
{
	if (index < 0 || index >= this->size)
	{
		std::cout << "Error! Cannot shift left from invalid index.\n";
		return;
	}

	int writeIndex = index;
	int readIndex = index + 1;
	while (readIndex < this->size)
	{
		this->arr[writeIndex] = this->arr[readIndex];
		writeIndex++;
		readIndex++;
	}
}

// Shift the array with one position right from given index
void List::shiftRight(int index)
{
	if (index < 0 || index >= this->size)
	{
		std::cout << "Error! Cannot shift right from invalid index.\n";
		return;
	}
	
	int writeIndex = this->size - 1;
	int readIndex = this->size - 2;
	while (readIndex >= index)
	{
		this->arr[writeIndex] = this->arr[readIndex];
		writeIndex--;
		readIndex--;
	}
}
