#pragma once
#include "Building.h"

class House : public Building
{
public:
	House();
	House(int height, double area, const char* address, int storeys, const char* ownerName);
	House(const House& other);
	House& operator=(const House& rhs);
	~House();

	int getStoreys() const;
	const char* getOwnerName() const;

	void setStoreys(int storeys);
	void setOwnerName(const char* name);

	void read();
	void print() const;
private:
	int storeys;
	char* ownerName;
};