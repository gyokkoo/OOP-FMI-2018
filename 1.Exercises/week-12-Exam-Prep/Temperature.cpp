#include <iostream>
#include "Temperature.h"

Temperature::Temperature() 
	: min(DEFAULT_VALUE), avg(DEFAULT_VALUE), max(DEFAULT_VALUE)
{
}

Temperature::Temperature(int min, int avg, int max)
{
	this->setTemperatures(min, avg, max);
}

void Temperature::setTemperatures(int min, int avg, int max)
{
	if (isValidTemperature(min, avg, max))
	{
		this->min = min;
		this->avg = avg;
		this->max = max;
	}
	else
	{
		this->min = DEFAULT_VALUE;
		this->avg = DEFAULT_VALUE;
		this->max = DEFAULT_VALUE;
	}
}

int Temperature::getMin() const
{
	return this->min;
}

int Temperature::getAvg() const
{
	return this->avg;
}

int Temperature::getMax() const
{
	return this->max;
}

int Temperature::getAmplitude() const
{
	return this->getMax() - this->getMin();
}

void Temperature::print() const
{
	std::cout
		<< "Min: " << this->getMin() << ", "
		<< "Avg: " << this->getAvg() << ", "
		<< "Max: " << this->getMax() << ", "
		<< "Amplitude: " << this->getAmplitude() << "\n";
}

bool Temperature::isValidTemperature(int min, int avg, int max)
{
	return min <= avg && avg <= max;
}

bool operator<(const Temperature & lhs, const Temperature & rhs)
{
	if (lhs.getMax() < rhs.getMax())
	{
		return true;
	}
	else if (lhs.getMax() == rhs.getMax() && lhs.getMin() < rhs.getMin())
	{
		return true;
	}
	else if (lhs.getMax() == rhs.getMax() && lhs.getMin() == rhs.getMin() &&
		lhs.getAvg() < rhs.getAvg())
	{
		return true;
	}

	return false;
}

bool operator>(const Temperature & lhs, const Temperature & rhs)
{
	return rhs < lhs;
}

bool operator<=(const Temperature & lhs, const Temperature & rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const Temperature & lhs, const Temperature & rhs)
{
	return !(lhs < rhs);
}

bool operator==(const Temperature & lhs, const Temperature & rhs)
{
	return !(lhs < rhs) && !(rhs < lhs);
}

bool operator!=(const Temperature & lhs, const Temperature & rhs)
{
	return !(lhs == rhs);
}
