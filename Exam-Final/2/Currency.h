#pragma once
#include <string>

class Currency
{
public:
	Currency(const std::string& name);
	Currency(const std::string& name, double rate);

	void setRate(double rate);

	const std::string& getName() const;
	const double getRate() const;
private:
	std::string name;
	double rate;
};

std::ostream& operator<<(std::ostream& os, const Currency& currency);