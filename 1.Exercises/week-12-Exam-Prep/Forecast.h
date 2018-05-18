#pragma once
#include <iostream>
#include "Temperature.h"

class Forecast : public Temperature
{
public:
	Forecast();
	Forecast(const char* place, const Temperature& temp);
	Forecast(const Forecast& other);
	Forecast& operator=(const Forecast& rhs);
	~Forecast();

	const char* getPlace() const;
	const Temperature getTemperature() const;

	void setPlace(const char* name);

	bool updateIfHotter(const Forecast& f);
private:
	char* placeName;
};

std::istream& operator>>(std::istream& is, Forecast& forecast);
std::ostream& operator<<(std::ostream& os, const Forecast& forecast);