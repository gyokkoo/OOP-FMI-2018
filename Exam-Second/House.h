#pragma once
#include "Building.h"

class House : public Building
{
public:
	House();
	House(int height, int area, int storeys, int rooms, const char* ownerName);
	House(const House& other);
	House& operator=(const House& rhs);
	~House();

	int getRooms() const;
	const char* getOwnerName() const;

	void setRooms(int rooms);
	void setOwnerName(const char* ownerName);
private:
	int rooms;
	char* ownerName;
};

bool operator<(const House& lhs, const House& rhs);
std::ostream& operator<<(std::ostream& os, const House& house);