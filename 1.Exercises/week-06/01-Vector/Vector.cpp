#include <iostream>
#include "Vector.h"

Vector::Vector(double x, double y, double z)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
}

Vector Vector::add(const Vector & vector) const
{
	Vector result;
	result.setX(this->getX() + vector.getX());
	result.setY(this->getY() + vector.getY());
	result.setZ(this->getZ() + vector.getZ());

	return result;
}

Vector Vector::operator+(const Vector & vector) const
{
	Vector result;
	result.setX(this->getX() + vector.getX());
	result.setY(this->getY() + vector.getY());
	result.setZ(this->getZ() + vector.getZ());

	return result;
}

void Vector::print() const
{
	std::cout << this->getX() << " " << this->getY() << " " << this->getZ() << "\n";
}

void Vector::setX(double x)
{
	this->x = x;
}

void Vector::setY(double y)
{
	this->y = y;
}

void Vector::setZ(double z)
{
	this->z = z;
}

double Vector::getX() const
{
	return this->x;
}

double Vector::getY() const
{
	return this->y;
}

double Vector::getZ() const
{
	return this->z;
}
