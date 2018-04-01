#include <iostream>
#include "Vector.h"

Vector::Vector(double x, double y, double z)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
}

Vector Vector::operator+(const Vector & vector) const
{
	Vector result;
	result.setX(this->getX() + vector.getX());
	result.setY(this->getY() + vector.getY());
	result.setZ(this->getZ() + vector.getZ());

	return result;
}

Vector Vector::operator-(const Vector & vector) const
{
	Vector result;
	result.setX(this->getX() - vector.getX());
	result.setY(this->getY() - vector.getY());
	result.setZ(this->getZ() - vector.getZ());

	return result;
}

Vector Vector::operator*(double lambda) const
{
	Vector result;
	result.setX(lambda * this->getX());
	result.setY(lambda * this->getY());
	result.setZ(lambda * this->getZ());
	return result;
}

double Vector::operator*(const Vector & b) const
{
	return 
		this->getX() * b.getX() + 
		this->getY() * b.getY() + 
		this->getZ() * b.getZ();
}

Vector Vector::operator^(const Vector & b) const
{
	Vector result;
	result.setX(this->getY() * b.getZ() - this->getZ() * b.getY());
	result.setY(this->getZ() * b.getX() - this->getX() * b.getZ());
	result.setZ(this->getX() * b.getY() - this->getY() * b.getX());
	return result;
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
