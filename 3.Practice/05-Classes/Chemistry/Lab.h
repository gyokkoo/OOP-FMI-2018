#pragma once
#include "Sensor.h"

const int INITIAL_CAPACITY = 2;
const int MAX_NAME_SIZE = 30;

class Lab
{
public:
	Lab();
	Lab(const char* name);
	Lab(const Lab& lab);
	Lab & operator=(const Lab& other);

	~Lab();

	void addSensor(const Sensor& sensor);
	
	const char* getName() const; 
	void setName(const char* name);

	double getAverageTemperature() const;
private:
	char* name;
	int count;
	int capacity;
	Sensor* sensors;

	void resize(int capacity);
};