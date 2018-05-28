#include "Truck.h"

Truck::Truck() : Vehicle(), size(0.0)
{
}

Truck::Truck(const char* make, const char* model, Color color, int year, int mileage, int size)
	: Vehicle(make, model, color, year, mileage)
{
	this->setSize(size);
}

Truck::~Truck()
{
}

double Truck::getSize() const
{
	return this->size;
}

void Truck::setSize(int size)
{
	if (size < 0)
	{
		std::cout << "Error! Invalid size, cannot be negative!\n";
		this->size = 0;
		return;
	}

	this->size = size;
}

void Truck::details() const
{
	std::cout << "Truck:\n";
	Vehicle::details();
	std::cout << "--Size    -> " << this->getSize() << " metres\n\n";
}
