#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle(), type(nullptr)
{
}

Motorcycle::Motorcycle(const char* make, const char* model, Color color, int year, int mileage, const char* type)
	: Vehicle(make, model, color, year, mileage), type(nullptr)
{
	this->setType(type);
}

Motorcycle::Motorcycle(const Motorcycle& other)
	: Vehicle(other), type(nullptr)
{
	this->setType(other.type);
}

Motorcycle& Motorcycle::operator=(const Motorcycle& rhs)
{
	if (this != &rhs)
	{
		Vehicle::operator=(rhs);
		this->setType(type);
	}

	return *this;
}

Motorcycle::~Motorcycle()
{
	delete[] this->type;
}

const char* Motorcycle::getType() const
{
	if (this->type == nullptr)
	{
		return "No Type";
	}

	return this->type;
}

void Motorcycle::setType(const char* type)
{
	if (type == nullptr)
	{
		std::cout << "Error! Invalid motorcycle type, cannot be nullptr.\n";
		this->type = nullptr;
	}

	delete[] this->type;
	int length = strlen(type) + 1;
	this->type = new char[length];
	strcpy_s(this->type, length, type);
}

void Motorcycle::details() const
{
	std::cout << "Motorcycle:\n";
	Vehicle::details();
	std::cout << "--Type    -> " << this->getType() << "\n\n";
}