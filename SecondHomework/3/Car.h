#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(const char* make, const char* model, Color color, int year, int mileage);
	virtual ~Car();

	virtual void details() const;
};