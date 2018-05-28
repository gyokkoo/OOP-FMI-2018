#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	Truck(const char* make, const char* model, Color color, int year, int mileage, int size);
	virtual ~Truck();

	double getSize() const;
	void setSize(int size);

	virtual void details() const;
private:
	double size;
};
