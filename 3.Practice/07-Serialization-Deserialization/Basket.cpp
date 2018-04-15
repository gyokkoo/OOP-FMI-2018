#include <fstream>
#include <iostream>
#include "Basket.h"

Basket::Basket(const char * name) : capacity(INITIAL_CAPACITY)
{
	this->count = 0;
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
		this->count = basket.count;
		this->eggs = new Egg[basket.capacity];
		for (int i = 0; i < basket.count; i++)
		{
			this->eggs[i] = basket.eggs[i];
		}
	}

	return *this;
}

void Basket::generateReport()
{
	char fileName[100] = "report_";
	std::cout << this->name << "\n";
	strcat_s(fileName, this->name);
	strcat_s(fileName, ".txt");
	
	std::ofstream os(fileName, std::ios::trunc);
	for (int i = 0; i < this->count; i++)
	{
		this->eggs[i].eggPrint(os);
	}
	os.close();
}

void Basket::serialization()
{
	char fileName[100] = "content_";
	strcat_s(fileName, this->name);
	strcat_s(fileName, ".dat");

	std::ofstream os(fileName, std::ios::binary | std::ios::trunc);
	if (!os)
	{
		std::cerr << "Error opening file: " << fileName << "\n";
		return;
	}

	os.write((const char*)& this->count, sizeof(this->count));
	for (int i = 0; i < this->count; i++)
	{
		this->eggs[i].eggSerialization(os);
	}
	os.close();
}

void Basket::deserialization()
{
	char fileName[100] = "content_";
	strcat_s(fileName, this->name);
	strcat_s(fileName, ".dat");

	std::ifstream is(fileName, std::ios::binary);
	if (!is)
	{
		std::cerr << "Error opening file: " << fileName << "\n";
		return;
	}

	int eggsCount = 0;
	is.read((char *)& eggsCount, sizeof(eggsCount));

	Egg egg;
	for (int i = 0; i < eggsCount; i++)
	{
		egg.eggDeserialization(is);
		this->addEgg(egg);
	}

	is.close();
}

void Basket::setName(const char * name)
{
	delete[] this->name;
	int nameLength = strlen(name);
	this->name = new char[nameLength + 1];
	for (int i = 0; i < nameLength; i++)
	{
		this->name[i] = name[i];
	}
	this->name[nameLength] = '\0';
}

void Basket::addEgg(const Egg& egg)
{
	if (this->getEggIndex(egg.getName()) != -1)
	{
		return;
	}

	if (this->count >= this->capacity)
	{
		resize();
	}

	this->eggs[count] = egg;
	count++;
}

void Basket::removeEgg(const Egg& egg)
{
	int indexToRemove = this->getEggIndex(egg.getName());
	if (indexToRemove == -1)
	{
		return;
	}
	
	count--;
	if (count != 0)
	{
		this->eggs[indexToRemove] = this->eggs[this->count];
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
	for (int i = 0; i < this->count; i++)
	{
		this->eggs[i] = temp[i];
	}

	delete[] temp;
	// std::cout << "Array was resized, new capacity: " << this->capacity << "\n";
}

int Basket::getEggIndex(const char * eggName)
{
	for (int i = 0; i < this->count; i++)
	{
		if (_stricmp(eggName, this->eggs[i].getName()) == 0)
		{
			return i;
		}
	}

	return -1;
}
