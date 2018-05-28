#pragma once
#include "ElectricDevice.h"

const int DEFAULT_CAPACITY = 2;

class ElectricNet
{
public:
	ElectricNet(int maxConsumption);
	ElectricNet(const ElectricNet& other);
	ElectricNet& operator=(const ElectricNet& rhs);
	~ElectricNet();

	ElectricNet& operator+=(const ElectricDevice& rhs);
	ElectricNet operator+(const ElectricDevice& rhs);

	ElectricNet& operator-=(const ElectricDevice& rhs);
	ElectricNet operator-(const ElectricDevice& rhs);

	ElectricDevice& operator[](const char* name);
	bool operator!();

	ElectricNet& operator++(); // pre-increment (e.g. ++a)
	ElectricNet operator++(int); // post-increment (e.g. a++)

	ElectricNet& operator--(); // pre-decrement
	ElectricNet operator--(int); // post-decrement

	int getCurrentConsumption() const;
	int getMaxConsumption() const;
	int getDevicesCount() const;
	int getCapacity() const;

	void setMaxConsumption(int maxConsumption);
	
	void print() const;
private:
	void clear();
	void copyFrom(const ElectricNet& other);
	void allocate(int size);
	void resize(int newCapacity);
	int getDeviceIndexByName(const char* name);
private:
	int maxConsumption;
	int capacity;
	int count;
	ElectricDevice* devices;
};