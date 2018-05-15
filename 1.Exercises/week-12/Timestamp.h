#pragma once

#include <iostream>
class Timestamp
{
public:
	Timestamp();
	Timestamp(unsigned long value);

	unsigned long getValue() const;

	void setValue(unsigned long value);

	void operator+=(const Timestamp& rhs);
	void operator+=(unsigned long rhs);

	Timestamp operator+(const Timestamp& rhs);
	Timestamp operator+(unsigned long rhs);
private:
	unsigned long time;
};

std::ostream& operator<<(std::ostream& os, const Timestamp& timestamp);
std::istream& operator>>(std::istream& is, Timestamp& timestamp);

