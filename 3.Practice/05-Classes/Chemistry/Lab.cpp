#include <iostream>
#include <string.h>
#include "Lab.h"

Lab::Lab() : name("NoName"), count(0), capacity(INITIAL_CAPACITY)
{
	this->sensors = new Sensor[INITIAL_CAPACITY];
}

Lab::Lab(const char* name)
{
	this->setName(name);
	this->capacity = INITIAL_CAPACITY;
	this->count = 0;
	this->sensors = new Sensor[INITIAL_CAPACITY];
}

Lab::Lab(const Lab& lab)
{
	this->setName(lab.name);
	this->count = lab.count;
	this->capacity = lab.capacity;
	this->sensors = new Sensor[lab.count];
	for (int i = 0; i < lab.count; i++)
	{
		this->sensors[i] = lab.sensors[i];
	}
}

Lab::~Lab()
{
	delete[] this->sensors;
}

void Lab::addSensor(const Sensor& sensor)
{
	if (this->count >= this->capacity)
	{
		resize(this->capacity * 2);
	}

	this->sensors[this->count] = sensor;
	this->count++;
}

const char* Lab::getName() const
{
	return this->name;
}

void Lab::setName(const char * name)
{
	strcpy_s(this->name, name);
}

double Lab::getAverageTemperature() const
{
	double sum = 0;
	for (int i = 0; i < this->count; i++)
	{
		sum += this->sensors[i].getTemperature();
	}

	if (this->count == 0)
	{
		return 0;
	}
	return sum / this->count;
}

void Lab::resize(int newCapacity)
{
	Sensor* temp = this->sensors;
	this->sensors = new Sensor[newCapacity];
	this->capacity = newCapacity;
	for (int i = 0; i < this->count; i++)
	{
		this->sensors[i] = temp[i];
	}

	delete[] temp;
	std::cout << "Sensors array was resized, new capacity: " << this->capacity << "\n";
}

