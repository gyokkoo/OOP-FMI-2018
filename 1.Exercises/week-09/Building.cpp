#include <iostream>
#include <cstring>

#include "Building.h"

Building::Building() : height(0), area(0.0), address(nullptr)
{
	std::cout << "Building class - default constructor! \n";
}

Building::Building(int height, double area, const char* address)
{
	std::cout << "Building class - constructor with parameters! \n";
	this->setHeight(height);
	this->setArea(area);
	this->setAddress(address);
}

Building::Building(const Building& other)
{
	std::cout << "Building class - copy constructor! \n";
	this->setHeight(other.height);
	this->setArea(other.area);
	this->setAddress(other.address);
}

Building& Building::operator=(const Building & rhs)
{
	std::cout << "Building class - operator = \n";
	// Check for self-assignment
	if (this != &rhs)
	{
		this->setHeight(rhs.height);
		this->setArea(rhs.area);
		this->setAddress(rhs.address);
	}

	return *this;
}

Building::~Building()
{
	std::cout << "Building class - destructor!\n";
	delete[] this->address;
}

int Building::getHeight() const
{
	return this->height;
}

double Building::getArea() const
{
	return this->area;
}

const char* Building::getAddress() const
{
	if (this->address == nullptr)
	{
		return "No address!\n";
	}

	return this->address;
}

void Building::setHeight(int height)
{
	if (height < 0)
	{
		std::cout << "Invalid height! Cannot be less than zeor!\n";
		this->height = 0;
		return;
	}

	this->height = height;
}

void Building::setArea(double area)
{
	if (area < 0)
	{
		std::cout << "Invalid area! Cannot be less than zero!\n";
		this->area = 0;
		return;
	}

	this->area = area;
}

void Building::setAddress(const char* address)
{
	delete[] this->address; // Delete previous address
	
	// Simple address validation 
	if (address == nullptr || strlen(address) < 3)
	{
		std::cout << "Invalid address! Must be at least 3 symbols!\n";
		this->address = nullptr;
		return;
	}
	
	int strLength = strlen(address);
	this->address = new char[strLength + 1];
	for (int i = 0; i < strLength; i++)
	{
		this->address[i] = address[i];
	}
	this->address[strLength] = '\0';
}

void Building::print() const
{
	std::cout << "Building class - print() \n"
		<< "Height -> " << this->getHeight() << "\n"
		<< "Area -> " << this->getArea() << "\n"
		<< "Address -> " << this->getAddress() << "\n";
}