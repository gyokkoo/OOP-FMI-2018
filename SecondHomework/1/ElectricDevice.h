#pragma once
#include <iostream>

class ElectricDevice
{
public:
	ElectricDevice();
	ElectricDevice(const char* name, int kW);
	ElectricDevice(const ElectricDevice& other);
	ElectricDevice& operator=(const ElectricDevice& rhs);
	~ElectricDevice();

	const char* getName() const;
	int getkW() const;

	void setName(const char* name);
	void setkW(int kW);
private:
	char* name;
	int kW;
};

std::ostream& operator<<(std::ostream& os, const ElectricDevice& e);