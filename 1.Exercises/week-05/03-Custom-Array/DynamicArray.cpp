#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() : size(0), capacity(INITIAL_CAPACITY)
{
	this->arr = new int[INITIAL_CAPACITY];
}

DynamicArray::DynamicArray(int capacity) : size(0)
{
	this->capacity = capacity;
	this->arr = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& dynamicArray)
{
	this->size = dynamicArray.size;
	this->capacity = dynamicArray.capacity;
	this->arr = new int[dynamicArray.capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = dynamicArray.arr[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] this->arr;
}

void DynamicArray::resize(int capacity)
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

void DynamicArray::insertAt(int i, int value)
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

void DynamicArray::pushBack(int value)
{
	if (this->size >= this->capacity)
	{
		resize(this->capacity * 2);
	}

	this->size++;
	this->arr[this->size - 1] = value;
}

int DynamicArray::popBack()
{
	if (this->size <= 0)
	{
		std::cout << "Error! Cannot pop empty array. Return -1\n";
		return -1;
	}

	int elementToRemove = this->arr[this->size - 1];
	this->size--;
	return elementToRemove;
}

void DynamicArray::removeAt(int i)
{
	if (i < 0 || i >= this->size)
	{
		std::cout << "Error! Array index out of bounds.\n";
		return;
	}

	shiftLeft(i);
	this->size--;
}

void DynamicArray::clear()
{
	delete[] this->arr;
	this->arr = nullptr;
	this->size = 0;
	this->capacity = INITIAL_CAPACITY;
	std::cout << "Array cleared!\n";
}

bool DynamicArray::isEmpty() const
{
	return this->size == 0;
}

int DynamicArray::getAt(int i) const
{
	if (i < 0 || i >= this->size)
	{
		std::cout << "Error! Array index out of bounds. Return -1.\n";
		return -1;
	}

	return this->arr[i];
}

int DynamicArray::getCapacity() const
{
	return this->capacity;
}

int DynamicArray::getSize() const
{
	return this->size;
}

void DynamicArray::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << " ";
	}
	std::cout << "\n";
}

// Shift the array with one position left from given index
void DynamicArray::shiftLeft(int index)
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
void DynamicArray::shiftRight(int index)
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
