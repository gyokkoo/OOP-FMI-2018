#include <cstring>
#include "Forecast.h"

Forecast::Forecast() : temperature(0, 0, 0), placeName(nullptr)
{
	this->setPlace("");
}

Forecast::Forecast(const char* place, const Temperature& temp) 
	: temperature(temp), placeName(nullptr)
{
	this->setPlace(place);
}

Forecast::Forecast(const Forecast& other) 
	: temperature(other.getTemperature()), placeName(nullptr)
{
	this->setPlace(other.placeName);
}

Forecast& Forecast::operator=(const Forecast& rhs)
{
	if (this != &rhs)
	{
		this->temperature = rhs.getTemperature();
		this->setPlace(rhs.placeName);
	}

	return *this;
}

Forecast::~Forecast()
{
	delete[] this->placeName;
}

const char* Forecast::getPlace() const
{
	if (this->placeName == nullptr)
	{
		return "";
	}

	return this->placeName;
}

const Temperature Forecast::getTemperature() const
{
	return this->temperature;
}

void Forecast::setPlace(const char* name)
{
	if (name == nullptr)
	{
		std::cout << "Invalid name provided!\n";
		return;
	}

	delete[] this->placeName;
	int length = strlen(name) + 1;
	this->placeName = new char[length];
	strcpy_s(this->placeName, length, name);
}

void Forecast::setTemperatures(int min, int avg, int max)
{
	this->temperature.setTemperatures(min, avg, max);
}

bool Forecast::updateIfHotter(const Forecast & f)
{
	// Check if place names are same
	if (!strcmp(this->getPlace(), f.getPlace()))
	{
		// Check if the given temperature is hotter
		if (f.getTemperature() > this->getTemperature())
		{
			int min = f.getTemperature().getMin();
			int avg = f.getTemperature().getAvg();
			int max = f.getTemperature().getMax();
			this->temperature.setTemperatures(min, avg, max);
			return true;
		}
	}
	return false;
}

std::istream & operator>>(std::istream & is, Forecast & forecast)
{
	char buffer[1000];
	int min, avg, max;
	
	std::cout << "Enter place name: ";
	is.getline(buffer, 1000);
	forecast.setPlace(buffer);
	
	std::cout << "Enter Min, Avg and Max temperatures:\n";
	is >> min >> avg >> max;
	forecast.setTemperatures(min, avg, max);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Forecast& forecast)
{
	os << "\nForecast in " << forecast.getPlace() << "\n";
	os << "Min: "    << forecast.getTemperature().getMin() 
		<< ", Avg: " << forecast.getTemperature().getAvg() 
		<< ", Max: " << forecast.getTemperature().getMax() << "\n";
	return os;
}
