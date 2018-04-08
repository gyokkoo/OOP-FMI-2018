#include <fstream>
#include <iostream>
#include "Basket.h"

Basket::Basket() : eggs(nullptr), size(0), capacity(0)
{
}

Basket::Basket(const char * name) : size(0), capacity(INITIAL_CAPACITY)
{
	this->setName(name);
	this->eggs = new Egg[this->capacity];
}

Basket::Basket(const Basket & basket)
{
	this->setName(basket.name);
	this->eggs = new Egg[basket.capacity];
}

Basket::~Basket()
{
	delete[] this->name;
	delete[] this->eggs;
}

Basket & Basket::operator=(const Basket & basket)
{
	if (this != &basket)
	{
		delete[] this->eggs;
		this->setName(basket.name);
		this->capacity = basket.capacity;
		this->size = basket.size;
		this->eggs = new Egg[basket.capacity];
		for (int i = 0; i < basket.size; i++)
		{
			this->eggs[i] = basket.eggs[i];
		}
	}

	return *this;
}

void Basket::generateReport()
{
	char fileName[100] = "report_";
	strcat_s(fileName, this->name);
	strcat_s(fileName, ".txt");
	std::cout << this->name << "\n";
	std::ofstream os(fileName, std::ios::trunc);
	for (int i = 0; i < this->size; i++)
	{
		this->eggs[i].serialization(os);
	}
	os.close();
}

void Basket::setName(const char * name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < this->size; i++)
	{
		this->name[i] = name[i];
	}
	this->name[strlen(name)] = '\0';
}

void Basket::addEgg(const char * eggName)
{
	if (this->size >= this->capacity)
	{
		resize();
	}

	Egg eggToAdd(eggName);
	this->eggs[size] = eggName;
	size++;
}

void Basket::removeEgg(const char * eggName)
{
	if (this->size == 0)
	{
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(this->eggs[i].getName(), eggName) == 0)
		{
			this->eggs[i] = nullptr;
			shiftLeft(i);
		}
	}
}

void Basket::resize()
{
	this->capacity *= 2;

	if (this->capacity < 0)
	{
		return;
	}

	// Save the current pointer, create new *array with new capacity, copy elements
	// then delete the old pointer
	Egg* temp = this->eggs;
	this->eggs = new Egg[capacity];
	this->capacity = capacity;
	for (int i = 0; i < this->size; i++)
	{
		this->eggs[i] = temp[i];
	}

	delete[] temp;
	std::cout << "Array was resized, new capacity: " << this->capacity << "\n";
}

void Basket::shiftLeft(int index)
{
	if (index < 0 || index >= this->size)
	{
		return;
	}

	int writeIndex = index;
	int readIndex = index + 1;
	while (readIndex < this->size)
	{
		this->eggs[writeIndex] = this->eggs[readIndex];
		writeIndex++;
		readIndex++;
	}
}
