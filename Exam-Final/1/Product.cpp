#include <iostream>
#include "Product.h"

Product::Product(Expression * first, Expression * second) : first(nullptr), second(nullptr)
{
	this->first = first->clone();
	this->second = second->clone();
}

Product::Product(const Product & other) : first(nullptr), second(nullptr)
{
	this->first = other.first->clone();
	this->second = other.second->clone();
}

Product & Product::operator=(const Product & rhs)
{
	if (this != &rhs)
	{
		delete this->first;
		delete this->second;
		this->first = rhs.first->clone();
		this->second = rhs.second->clone();
	}

	return *this;
}

Product::~Product()
{
	delete this->first;
	delete this->second;
}

Expression * Product::clone() const
{
	return new Product(*this);
}

double Product::value() const
{
	if (this->first == nullptr || this->second == nullptr)
	{
		std::cout << "Invalid expressions!\n";
		return 0;
	}

	return this->first->value() * this->second->value();
}

void Product::print() const
{
	std::cout << "Product: (";
	this->first->print();
	std::cout << " * ";
	this->second->print();
	std::cout << ") = " << this->value() << " ";
}
