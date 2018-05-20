#include <cstring>
#include "House.h"

House::House() : Building(), ownerName(nullptr), rooms(0)
{
}

House::House(int height, int area, int storeys, int rooms, const char* ownerName)
	: Building(height, area, storeys), ownerName(nullptr)
{
	this->setRooms(rooms);
	this->setOwnerName(ownerName);
}

House::House(const House& other) : Building(other), ownerName(nullptr)
{
	this->setRooms(other.rooms);
	this->setOwnerName(other.ownerName);
}

House& House::operator=(const House& rhs)
{
	if (this != &rhs)
	{
		// Invoke default assignment operator in Building class
		Building::operator=(rhs);
		this->setRooms(rhs.rooms);
		this->setOwnerName(rhs.ownerName);
	}

	return *this;
}

const char* House::getOwnerName() const
{
	if (this->ownerName == nullptr)
	{
		return "No name!";
	}

	return this->ownerName;
}

House::~House()
{
	delete[] this->ownerName;
}

int House::getRooms() const
{
	return this->rooms;
}

void House::setOwnerName(const char* ownerName)
{
	if (ownerName == nullptr)
	{
		std::cout << "Provided name is invalid (nullptr)!\n";
		this->ownerName = nullptr;
		return;
	}

	int length = strlen(ownerName) + 1;
	delete[] this->ownerName;
	this->ownerName = new char[length];
	strcpy_s(this->ownerName, length, ownerName);
}

void House::setRooms(int rooms)
{
	if (rooms < 0)
	{
		std::cout << "Invalid rooms count!\n";
		this->rooms = 0;
		return;
	}

	this->rooms = rooms;
}

bool operator<(const House& lhs, const House& rhs)
{
	return lhs.getRooms() < rhs.getRooms();
}

std::ostream& operator<<(std::ostream& os, const House& house)
{
	// Invoke operator<< for Building class

	// os << (const Building&)house;
	operator<<(os, (const Building&)house); // Another way
	os << "Rooms: " << house.getRooms() << "\n";
	os << "Owner name: " << house.getOwnerName() << "\n";
	return os;
}
