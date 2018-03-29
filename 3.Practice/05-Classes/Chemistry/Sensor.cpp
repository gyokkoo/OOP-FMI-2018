#include <iostream>
#include <string.h>
#include "Sensor.h"

Sensor::Sensor() : 
	id(0), temperature(0), description(nullptr)
{
}

Sensor::Sensor(int id, const char* description) :
	temperature(0)
{
	this->setId(id);
	this->setDescription(description);
}

Sensor::Sensor(const Sensor & sensor)
{
	this->setId(sensor.id);
	this->setTemperature(sensor.temperature);
	this->setDescription(sensor.description);
}

Sensor::~Sensor()
{
	delete[] this->description;
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

void Sensor::setId(int id)
{
	if (id < 0)
	{
		std::cout << "Invalid ID provided!\n";
		return;
	}

	this->id = id;
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