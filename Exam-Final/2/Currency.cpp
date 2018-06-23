#include "Currency.h"

Currency::Currency(const std::string & name)
{
	this->name = name;
	this->rate = 0;
}

Currency::Currency(const std::string& name, double rate)
{
	this->name = name;
	this->rate = rate;
}

void Currency::setRate(double rate)
{
	this->rate = rate;
}

const std::string & Currency::getName() const
{
	return this->name;
}

const double Currency::getRate() const
{
	return this->rate;
}

std::ostream & operator<<(std::ostream & os, const Currency & currency)
{
	os << currency.getName() << " " << currency.getRate();
	return os;
}
