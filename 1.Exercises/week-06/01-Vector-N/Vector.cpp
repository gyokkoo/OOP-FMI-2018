#include <iostream>
#include "Vector.h"

Vector::Vector() : coordinates(nullptr), dimension(0)
{
}

Vector::Vector(int dimension)
{
	this->setDimension(dimension);
	this->coordinates = new double[dimension];
}

Vector::Vector(double * coordinates, int dimension)
{
	this->setDimension(dimension);
	this->setCoordinates(coordinates);
}

Vector::Vector(const Vector & other)
{
	this->dimension = other.dimension;
	this->coordinates = new double[this->dimension];
	for (int i = 0; i < this->dimension; i++)
	{
		this->coordinates[i] = other.coordinates[i];
	}
}

Vector::~Vector()
{
	delete[] this->coordinates;
}

Vector & Vector::operator=(const Vector & vector)
{
	if (this != &vector)
	{
		delete[] this->coordinates;
		this->dimension = vector.dimension;
		this->setCoordinates(vector.coordinates);
	}

	return *this;
}

Vector Vector::operator+(const Vector & vector)
{
	Vector result(this->dimension);
	for (int i = 0; i < this->dimension; i++)
	{
		result.coordinates[i] = this->coordinates[i] + vector.coordinates[i];
	}

	return result;
}

Vector Vector::operator-(const Vector & vector)
{
	Vector result(this->dimension);
	for (int i = 0; i < this->dimension; i++)
	{
		result.coordinates[i] = this->coordinates[i] - vector.coordinates[i];
	}

	return result;
}

Vector Vector::operator*(double lambda)
{
	Vector result(this->dimension);
	for (int i = 0; i < this->dimension; i++)
	{
		result.coordinates[i] = this->coordinates[i] * lambda;
	}

	return result;
}

double Vector::operator[](int index) const
{
	if (index >= this->dimension) {
		std::cout << "Index out of bounds!\n";
		return this->coordinates[0];
	}

	return this->coordinates[index];
}

double * Vector::getCoordinates() const
{
	return this->coordinates;
}

int Vector::getDimension() const
{
	return this->dimension;
}

void Vector::setCoordinates(double * coordinates)
{
	delete[] this->coordinates;
	this->coordinates = new double[this->dimension];
	for (int i = 0; i < this->dimension; i++)
	{
		this->coordinates[i] = coordinates[i];
	}
}

void Vector::setDimension(int dimension)
{
	if (dimension < 0)
	{
		std::cout << "Invalid dimension!\n";
		this->dimension = 0;
		return;
	}
	this->dimension = dimension;
}


std::ostream & operator<<(std::ostream & os, const Vector & v)
{
	double* coordinates = v.getCoordinates();
	int size = v.getDimension();
	for (int i = 0; i < size; i++)
	{
		os << coordinates[i] << " ";
	}
	os << "\n";
	return os;
}

std::istream & operator>>(std::istream & is, Vector & v)
{
	int size;
	std::cout << "Enter vector dimension:\n";
	is >> size;
	if (size < 0)
	{
		std::cout << "Invalid size!\n";
		return is;
	}
	v.setDimension(size);
	std::cout << "Enter coordinates:\n";
	double* coordinates = new double[size];
	for (int i = 0; i < size; i++)
	{
		is >> coordinates[i];
	}

	v.setCoordinates(coordinates);
	delete[] coordinates;
	return is;
}
