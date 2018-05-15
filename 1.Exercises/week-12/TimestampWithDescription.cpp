#include <iostream>
#include <cstring>

#include "TimestampWithDescription.h"

// Default constructor - Invokes default constructor for Timestamp in initalizing list
TimestampWithDescription::TimestampWithDescription()
	: Timestamp(), description(nullptr)
{
}

// Constructor with parameters - Invokes constructor with parameters for Timestamp
TimestampWithDescription::TimestampWithDescription(unsigned long value, const char* description)
	: Timestamp(value), description(nullptr)
{
	// Note: If description is not set to nullptr, delete[] description will throw exception
	this->setDescription(description);
}

// Copy constructor - Invokes copy constructor for Timestamp (The default copy constructor)
TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& other)
	: Timestamp(other), description(nullptr)
{
	this->setDescription(other.description);
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& rhs)
{
	// Note: rhs means right hand side
	if (this != &rhs)
	{
		// Invoke the assignment operator from the Base (Timestamp) class
		Timestamp::operator=(rhs);
		this->setDescription(rhs.description);
	}

	return *this;
}

TimestampWithDescription::~TimestampWithDescription()
{
	// Note: The Derived class destructor automagically invokes the destructors for the base class.
	delete[] this->description;
}

const char* TimestampWithDescription::getDescription() const
{
	if (this->description == nullptr)
	{
		return "No description!\n";
	}

	return this->description;
}

void TimestampWithDescription::setDescription(const char* description)
{
	if (description == nullptr)
	{
		std::cout << "Invalid description provided!\n";
		return;
	}

	// setDescription is public method, so it is necessary to delete the previous description
	// delete[] on nullptr does nothing
	delete[] this->description;

	// Allocate new memory and copy provided description
	int length = strlen(description) + 1;
	this->description = new char[length];

	// Null terminator will be copied
	for (int i = 0; i < length; i++)
	{
		this->description[i] = description[i];
	}
}

std::istream& operator>>(std::istream& is, TimestampWithDescription& timestamp)
{
	// Casting to Timestamp and invoking operator>> for Timestamp class
	is >> (Timestamp&)timestamp;

	std::cout << "Enter timestamp description: \n";
	char buffer[1000];
	// is.ignore();
	is >> buffer;

	timestamp.setDescription(buffer);
	return is;
}

std::ostream & operator<<(std::ostream & os, const TimestampWithDescription& timestamp)
{
	os << "Timestamp with description:\n";

	// Casting to Timestamp and invoking operator<< for Timestamp class
	os << (const Timestamp&)timestamp;

	os << "Description: " << timestamp.getDescription() << "\n\n";
	return os;
}
