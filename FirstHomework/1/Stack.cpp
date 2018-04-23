#include <iostream>
#include "Stack.h"

Stack::Stack() : topIndex(0), capacity(INITIAL_CAPACITY)
{
	this->allocate(INITIAL_CAPACITY);
}

Stack::Stack(const Stack& other)
{
	this->copyFrom(other);
}

Stack& Stack::operator=(const Stack& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

Stack::~Stack()
{
	this->clear();
}

void Stack::push(double value)
{
	if (this->isFull())
	{
		resize();
	}

	this->arr[topIndex] = value;
	this->topIndex++;
}

double Stack::pop()
{
	if (this->isEmpty())
	{
		std::cout << "Cannot pop empty stack! Return -1\n";
		return -1;
	}

	double elementToRemove = this->arr[this->topIndex - 1];
	this->topIndex--;
	return elementToRemove;
}

double Stack::peek() const
{
	if (this->isEmpty())
	{
		std::cout << "Cannot peek empty stack! Return -1\n";
		return -1;
	}

	return this->arr[this->topIndex - 1];
}

bool Stack::isEmpty() const
{
	return this->topIndex == 0;
}

// private methods
void Stack::allocate(int n)
{
	this->arr = new double[n];
}

void Stack::copyFrom(const Stack& other)
{
	this->topIndex = other.topIndex;
	this->capacity = other.capacity;
	for (int i = 0; i < other.topIndex; i++)
	{
		this->arr[i] = arr[i];
	}
}

void Stack::clear()
{
	delete[] this->arr;
	this->arr = nullptr;
	this->topIndex = 0;
	this->capacity = 0;
}

void Stack::resize()
{
	double* temp = this->arr;
	this->allocate(this->capacity * 2);
	for (int i = 0; i < this->topIndex; i++)
	{
		this->arr[i] = temp[i];
	}

	delete[] temp;
	this->capacity *= 2;
}

bool Stack::isFull() const
{
	return this->topIndex >= this->capacity;
}
