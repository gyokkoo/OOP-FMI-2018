#include <iostream>

#include "Timestamp.h"

Timestamp::Timestamp() : time(0)
{
}

Timestamp::Timestamp(unsigned long value)
{
	this->setValue(value);
}

unsigned long Timestamp::getValue() const
{
	return this->time;
}

void Timestamp::setValue(unsigned long value)
{
	this->time = value;
}

void Timestamp::operator+=(const Timestamp & rhs)
{
	this->time += rhs.getValue();
}

void Timestamp::operator+=(unsigned long rhs)
{
	this->time += rhs;
}

Timestamp Timestamp::operator+(const Timestamp & rhs)
{
	return operator+(rhs.getValue());
}

Timestamp Timestamp::operator+(unsigned long value)
{
	Timestamp result;
	result.setValue(this->getValue() + value);
	return result;
}

std::ostream& operator<<(std::ostream& os, const Timestamp & timestamp)
{
	std::cout << "seconds ~ ";
	os << timestamp.getValue() << " seconds.\n";
	return os;
}

std::istream& operator>>(std::istream& is, Timestamp & timestamp)
{
	std::cout << "Enter time in seconds: \n";
	unsigned long input;
	is >> input;
	timestamp.setValue(input);
	return is;
}
