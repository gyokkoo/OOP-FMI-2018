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

double Vector::operator*(const Vector & v) const
{
	return 
		this->getX() * v.getX() + 
		this->getY() * v.getY() + 
		this->getZ() * v.getZ();
}

Vector Vector::operator^(const Vector & v) const
{
	Vector result;
	result.setX(this->getY() * v.getZ() - this->getZ() * v.getY());
	result.setY(this->getZ() * v.getX() - this->getX() * v.getZ());
	result.setZ(this->getX() * v.getY() - this->getY() * v.getX());
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

Vector operator*(double lambda, const Vector & v)
{
	Vector result;
	result.setX(lambda * v.getX());
	result.setY(lambda * v.getY());
	result.setZ(lambda * v.getZ());
	return result;
}

std::ostream & operator<<(std::ostream & os, const Vector & v)
{
	os << "{" << v.getX() << ", " << v.getY() << ", " << v.getZ() << " }";
	return os;
}

std::istream & operator>>(std::istream & is, Vector & v)
{
	double temp;
	std::cout << "Enter X = ";
	is >> temp;
	v.setX(temp);
	std::cout << "Enter Y = ";
	is >> temp;
	v.setY(temp);
	std::cout << "Enter Z = ";
	is >> temp;
	v.setZ(temp);
	return is;
}
