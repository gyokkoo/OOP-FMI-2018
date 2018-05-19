#include <iostream>
#include "Marker.h"

Marker::Marker() : WritingInstrument(), color(nullptr)
{
}

Marker::Marker(const Marker& other) : WritingInstrument(other), color(nullptr)
{
	this->setColor(other.color);
}

Marker& Marker::operator=(const Marker& rhs)
{
	if (this != &rhs)
	{
		WritingInstrument::operator=(rhs);
		this->setColor(rhs.color);
	}

	return *this;
}

Marker::~Marker()
{
	delete[] this->color;
}

const char* Marker::getColor() const
{
	if (this->color == nullptr)
	{
		return "No color!";
	}

	return this->color;
}

void Marker::setColor(const char* color)
{
	if (color == nullptr)
	{
		std::cout << "Invalid color!\n";
	}

	delete[] this->color;
	int length = strlen(color) + 1;
	this->color = new char[length];
	strcpy_s(this->color, length, color);
}

std::istream& operator>>(std::istream& is, Marker& marker)
{
	char buffer[1001];
	
	is >> (WritingInstrument&) marker;
	std::cout << "Enter color: ";
	is.get();
	is.getline(buffer, 1000);
	marker.setColor(buffer);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Marker& marker)
{
	os << (const WritingInstrument&)marker;
	os << "Color: " << marker.getColor() << "\n";
	return os;
}