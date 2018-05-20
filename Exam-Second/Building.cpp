#include <iostream>
#include "Building.h"

Building::Building() : height(0), area(0), storeys(0)
{
}

Building::Building(int height, int area, int storeys)
{
	this->setHeight(height);
	this->setArea(area);
	this->setStoreys(storeys);
}

int Building::getHeight() const
{
	return this->height;
}

int Building::getArea() const
{
	return this->area;
}

int Building::getStoreys() const
{
	return this->storeys;
}

void Building::setHeight(int height)
{
	if (height < 0)
	{
		std::cout << "Invalid height!\n";
		this->height = 0;
		return;
	}

	this->height = height;
}

void Building::setArea(int area)
{
	if (area < 0)
	{
		std::cout << "Invalid area!\n";
		this->area = 0;
		return;
	}

	this->area = area;
}

void Building::setStoreys(int storeys)
{
	if (storeys < 0)
	{
		std::cout << "Invalid storeys!\n";
		this->storeys = 0;
		return;
	}

	this->storeys = storeys;
}

int Building::getTotalArea() const
{
	return this->area * this->storeys;
}

bool operator<(const Building& lhs, const Building& rhs)
{
	return lhs.getTotalArea() < rhs.getTotalArea();
}

std::ostream& operator<<(std::ostream& os, const Building & building)
{
	os << "--------------------------\n";
	os << "Height: " << building.getHeight() << "\n"
		<< "Area: " << building.getArea() << "\n"
		<< "Storeys: " << building.getStoreys() << "\n"
		<< "Total area: " << building.getTotalArea() << "\n";
	return os;
}
