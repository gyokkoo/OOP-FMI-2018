#include "Company.h"
#include <cstring>

Company::Company() : name("No name"), bulstat(0)
{
}

Company::Company(const char* name, long long bulstat) : Company::Company()
{
	strcpy_s(this->name, name);
	this->bulstat = bulstat;
}

const char* Company::getName() const
{
	return this->name;
}

long long Company::getBulstat() const
{
	return this->bulstat;
}

std::ostream & operator<<(std::ostream & os, const Company & company)
{
	os << company.getName() << " " 
		<< company.getBulstat() << "\n";
	return os;
}
