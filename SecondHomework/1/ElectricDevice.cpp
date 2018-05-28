#include "ElectricDevice.h"

ElectricDevice::ElectricDevice() : name(nullptr), kW(0)
{
}

ElectricDevice::ElectricDevice(const char* name, int kW) : name(nullptr)
{
	this->setName(name);
	this->setkW(kW);
}

ElectricDevice::ElectricDevice(const ElectricDevice& other) : name(nullptr)
{
	this->setName(other.name);
	this->setkW(other.kW);
}

ElectricDevice& ElectricDevice::operator=(const ElectricDevice& rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.name);
		this->setkW(rhs.kW);
	}

	return *this;
}

ElectricDevice::~ElectricDevice()
{
	delete[] this->name;
}

const char* ElectricDevice::getName() const
{
	if (this->name == nullptr)
	{
		return "Invalid name!\n";
	}

	return this->name;
}

int ElectricDevice::getkW() const
{
	return this->kW;
}

void ElectricDevice::setName(const char* name)
{
	if (name == nullptr)
	{
		std::cout << "Error! Invalid name, cannot be nullptr.\n";
		this->name = nullptr;
		return;
	}

	delete[] this->name;
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

void ElectricDevice::setkW(int kW)
{
	if (kW < 0)
	{
		std::cout << "Error! Invalid kW, cannot be negative!\n";
		this->kW = 0;
		return;
	}

	this->kW = kW;
}

std::ostream& operator<<(std::ostream & os, const ElectricDevice & e)
{
	os << e.getkW() << " kW -> " << e.getName() << "" << "\n";
	return os;
}
