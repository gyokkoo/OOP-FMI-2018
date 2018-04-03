#include <iostream>
#include <string.h>
#include "Sensor.h"

static unsigned int ID = 0;

Sensor::Sensor() : 
	id(ID++), temperature(0), description(nullptr)
{
}

Sensor::Sensor(const char* description) : id(ID++), temperature(0)
{
	this->setDescription(description);
}

Sensor::Sensor(const Sensor & sensor)
{
	this->id = sensor.id;
	this->setTemperature(sensor.temperature);
	this->setDescription(sensor.description);
}

Sensor::~Sensor()
{
	delete[] this->description;
}

Sensor & Sensor::operator=(const Sensor& s)
{
	if (this != &s)
	{
		this->id = s.id;
		this->temperature = s.temperature;

		int length = strlen(s.getDescription());
		this->description = new char[length + 1];
		strcpy_s(this->description, length + 1, s.getDescription());
	}

	return *this;
}

int Sensor::getId() const
{
	return this->id;
}

double Sensor::getTemperature() const
{
	// attach sensor here
	return this->temperature;
}

const char * Sensor::getDescription() const
{
	if (this->description == nullptr)
	{
		return "No description";
	}

	return this->description;
}

void Sensor::setTemperature(double temperature)
{
	if (temperature < -200 || temperature > 1750)
	{
		std::cout << "Invalid temperature range.\n";
		return;
	}

	this->temperature = temperature;
}

void Sensor::setDescription(const char* description)
{
	int length = strlen(description);
	int i = 0;
	char* temp = this->description;
	this->description = new char[length + 1];
	while ((this->description[i] = description[i]) != '\0')
	{
		i++;
	}
	delete[] temp;
}