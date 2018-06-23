#include <iostream>
#include "Const.h"

Const::Const(double value)
{
	this->val = value;
}

Expression* Const::clone() const
{
	return new Const(*this);
}

double Const::value() const
{
	return this->val;
}

void Const::print() const
{
	std::cout << this->value() << " ";
}
