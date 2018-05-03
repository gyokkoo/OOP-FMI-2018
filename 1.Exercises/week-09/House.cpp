#include <iostream>
#include "House.h"

House::House() : Building(), storeys(0), ownerName(nullptr)
{
	std::cout << "House class - default constructor!\n";
}

House::House(int height, double area, const char* address, int storeys, const char* ownerName)
	: Building(height, area, address), ownerName(nullptr)
{
	std::cout << "House class - constructor with parameters!\n";
	this->setStoreys(storeys);
	this->setOwnerName(ownerName);
}

House::House(const House& other) : Building(other), ownerName(nullptr)
{
	std::cout << "House class - copy constructor! \n";
	this->setStoreys(storeys);
	this->setOwnerName(ownerName);
}

House& House::operator=(const House& rhs)
{
	std::cout << "House class - operator = \n";
	if (this != &rhs)
	{
		Building::operator=(rhs);
		this->setStoreys(rhs.storeys);
		this->setOwnerName(rhs.ownerName);
	}

	return *this;
}

House::~House()
{
	std::cout << "House class - destructor! \n";
	delete[] this->ownerName;
}

int House::getStoreys() const
{
	return this->storeys;
}

const char* House::getOwnerName() const
{
	if (this->ownerName == nullptr)
	{
		return "No owner name!\n";
	}

	return this->ownerName;
}

void House::setStoreys(int storeys)
{
	this->storeys = storeys;
}

void House::setOwnerName(const char* ownerName)
{
	delete[] this->ownerName;
	
	int strLength = strlen(ownerName);
	this->ownerName = new char[strLength + 1];
	for (int i = 0; i < strLength; i++)
	{
		this->ownerName[i] = ownerName[i];
	}
	this->ownerName[strLength] = '\0';
}

void House::read()
{
	Building::read();

	int storeys = 0;
	int nameLength = 1024;
	char* name = new char[nameLength];

	std::cout << "Enter house storeys = ";
	std::cin >> storeys;
	this->setStoreys(storeys);

	std::cout << "Enter owner name: ";
	std::cin.ignore();
	std::cin.getline(name, nameLength - 1);
	this->setOwnerName(name);
	delete[] name;
}

void House::print() const
{
	std::cout << "House class - print() \n";
	Building::print();
	std::cout 
		<< "Storeys -> " << this->getStoreys() << "\n"
		<< "Owner name -> " << this->getOwnerName() << "\n";
	std::cout << "---------------------\n";
}