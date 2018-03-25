#include "Stack.h"
#include <iostream>

Stack::Stack() : topIndex(0), maxSize(INITIAL_SIZE)
{
	this->arr = new int[INITIAL_SIZE];
}

Stack::Stack(const Stack& other)
{
	this->maxSize = other.maxSize;
	this->topIndex = other.topIndex;
	this->arr = new int[other.maxSize];
	for (int i = 0; i < this->topIndex; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

Stack::~Stack()
{
	delete[] this->arr;
}

void Stack::push(int a)
{
	if (this->topIndex >= this->maxSize)
	{
		resize();
	}

	this->arr[this->topIndex] = a;
	this->topIndex++;
}

int Stack::pop()
{
	if (this->topIndex == 0)
	{
		std::cout << "Cannot pop empty stack! Return -1\n";
		return -1;
	}

	int elementToRemove = this->arr[this->topIndex - 1];
	this->topIndex--;
	return elementToRemove;
}

int Stack::peek() const
{
	if (this->topIndex == 0)
	{
		std::cout << "Cannot peek empty stack! Return -1\n";
		return -1;
	}

	return this->arr[this->topIndex - 1];
}

int Stack::getLength() const
{
	return this->topIndex;
}

void Stack::resize()
{
	int* temp = this->arr;
	this->arr = new int[this->maxSize * 2];
	for (int i = 0; i < this->topIndex; i++) 
	{
		this->arr[i] = temp[i];
	}
	
	delete[] temp;
	this->maxSize *= 2;
	std::cout << "The stack is resized! New Size: " << this->maxSize << "\n";
}