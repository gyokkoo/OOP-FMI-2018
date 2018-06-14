#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	Motorcycle(const char* make, const char* model, Color color, int year, int mileage, const char* type);
	Motorcycle(const Motorcycle& other);
	Motorcycle& operator=(const Motorcycle& rhs);
	virtual ~Motorcycle();

	const char* getType() const;
	void setType(const char* type);

	virtual void details() const override;
private:
	char* type;
};