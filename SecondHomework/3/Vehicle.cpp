#include "Vehicle.h"
#include <cstring>

Vehicle::Vehicle() : 
	make(nullptr), model(nullptr), color(INVALID_COLOR), year(0), mileage(0)
{
}

Vehicle::Vehicle(const char* make, const char* model, Color color, int year, int mileage)
	: make(nullptr), model(nullptr)
{
	this->setMake(make);
	this->setModel(model);
	this->setColor(color);
	this->setYear(year);
	this->setMileage(mileage);
}

Vehicle::Vehicle(const Vehicle& other)
{
	this->copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

Vehicle::~Vehicle()
{
	this->clear();
}

const char* Vehicle::getMake() const
{
	if (this->make == nullptr)
	{
		return "No Make";
	}

	return this->make;
}

const char * Vehicle::getModel() const
{
	if (this->model == nullptr)
	{
		return "No Model";
	}

	return this->model;
}

Color Vehicle::getColor() const
{
	return this->color;
}

int Vehicle::getYear() const
{
	return this->year;
}

int Vehicle::getMileage() const
{
	return this->mileage;
}

void Vehicle::setMake(const char* make)
{
	this->setString(this->make, make);
}

void Vehicle::setModel(const char* model)
{
	this->setString(this->model, model);
}

void Vehicle::setColor(Color color)
{
	this->color = color;
}

void Vehicle::setYear(int year)
{
	this->year = year;
}

void Vehicle::setMileage(int mileage)
{
	this->mileage = mileage;
}

void Vehicle::details() const
{
	std::cout
		<< "--Make    -> " << this->getMake() << "\n"
		<< "--Model   -> " << this->getModel() << "\n"
		<< "--Color   -> " << getColorString(this->getColor()) << "\n"
		<< "--Year    -> " << this->getYear() << " year\n"
		<< "--Mileage -> " << this->getMileage() << " miles\n";
}

void Vehicle::setString(char*& destination, const char* source)
{
	// Set source to destination string
	delete[] destination;
	int length = strlen(source) + 1;
	destination = new char[length];
	strcpy_s(destination, length, source);
}

void Vehicle::copyFrom(const Vehicle& other)
{
	this->setMake(other.make);
	this->setModel(other.model);
	this->setColor(other.color);
	this->setYear(other.year);
	this->setMileage(other.mileage);
}

void Vehicle::clear()
{
	delete[] this->make;
	this->make = nullptr;
	delete[] this->model;
	this->model = nullptr;
}
