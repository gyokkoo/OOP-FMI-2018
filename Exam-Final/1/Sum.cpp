#include <iostream>
#include "Sum.h"

Sum::Sum(Expression* first, Expression* second) : first(nullptr), second(nullptr)
{
	this->first = first->clone();
	this->second = second->clone();
}

Sum::Sum(const Sum& other)
{
	this->first = other.first->clone();
	this->second = other.second->clone();
}

Sum & Sum::operator=(const Sum & rhs)
{
	if (this != &rhs)
	{
		delete first;
		delete second;
		this->first = rhs.first->clone();
		this->second = rhs.second->clone();
	}

	return *this;
}

Sum::~Sum()
{
	delete first;
	delete second;
}

Expression* Sum::clone() const
{
	return new Sum(*this);
}

double Sum::value() const
{
	if (this->first == nullptr || this->second == nullptr)
	{
		std::cout << "Invalid expressions!\n";
		return 0;
	}

	return this->first->value() + this->second->value();
}

void Sum::print() const
{	
	std::cout << "Sum: (";
	this->first->print();
	std::cout << " + ";
	this->second->print();
	std::cout << ") = " << this->value() << " ";
}
