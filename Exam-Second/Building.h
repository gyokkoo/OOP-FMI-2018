#pragma once
#include <iostream>

class Building
{
public:
	Building();
	Building(int height, int area, int storeys);

	int getHeight() const;
	int getArea() const;
	int getStoreys() const;

	void setHeight(int height);
	void setArea(int area);
	void setStoreys(int storeys);

	int getTotalArea() const;
private:
	int height;
	int area;
	int storeys;
};

bool operator<(const Building& lhs, const Building& rhs);
std::ostream& operator<<(std::ostream& os, const Building& building);