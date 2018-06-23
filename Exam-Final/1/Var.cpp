#include <iostream>
#include <cstring> // strlen

#include "Var.h"

Var::Var() : val(0), name(nullptr)
{
	this->setName("No name");
}

Var::Var(double value, const char* name) : name(nullptr)
{
	this->setValue(value);
	this->setName(name);
}

Var::Var(const Var& other) : name(nullptr)
{
	this->setValue(other.val);
	this->setName(other.name);
}

Var& Var::operator=(const Var& rhs)
{
	if (this != &rhs)
	{
		this->setValue(rhs.val);
		this->setName(rhs.name);
	}

	return *this;
}

Var::~Var()
{
	delete[] this->name;
}

Expression* Var::clone() const
{
	return new Var(*this);
}

void Var::setName(const char* name)
{
	if (name == nullptr)
	{
		std::cout << "Invalid name, cannot be nullptr!\n";
		return;
	}

	int length = strlen(name) + 1;

	delete[] this->name;
	this->name = new char[length];

	for (int i = 0; i < length; ++i)
	{
		this->name[i] = name[i];
	}
}

void Var::setValue(double value)
{
	this->val = value;
}

const char* Var::getName() const
{
	if (this->name == nullptr)
	{
		return "No name";
	}

	return this->name;
}

double Var::value() const
{
	return this->val;
}

void Var::print() const
{
	std::cout << "(" << this->getName() << ", " << this->value() << ") ";
}
