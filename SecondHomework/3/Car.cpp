#include "Car.h"

Car::Car() : Vehicle()
{
}

Car::Car(const char* make, const char* model, Color color, int year, int mileage)
	: Vehicle(make, model, color, year, mileage)
{
}

Car::~Car()
{
}

void Car::details() const
{
	std::cout << "Car:\n";
	Vehicle::details();
	std::cout << "\n";
}
