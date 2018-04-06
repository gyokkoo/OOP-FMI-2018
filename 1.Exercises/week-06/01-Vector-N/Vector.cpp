#include <iostream>
#include "Vector.h"

Vector::Vector() : coordinates(nullptr), dimension(0)
{
}

Vector::Vector(int dimension) : coordinates(nullptr)
{
	this->dimension = dimension;
}

Vector::Vector(double * coordinates, int dimension)
{
	this->dimension = dimension;
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
	double* coordinates = new double[this->dimension];
	for (int i = 0; i < this->dimension; i++)
	{
		coordinates[i] = this->coordinates[i] + vector.coordinates[i];
	}

	result.setCoordinates(coordinates);
	delete[] coordinates;

	return result;
}

Vector Vector::operator-(const Vector & vector)
{
	Vector result(this->dimension);
	double* coordinates = new double[this->dimension];
	for (int i = 0; i < this->dimension; i++)
	{
		coordinates[i] = this->coordinates[i] - vector.coordinates[i];
	}

	result.setCoordinates(coordinates);
	delete[] coordinates;

	return result;
}

Vector Vector::operator*(double lambda)
{
	Vector result(this->dimension);
	double* coordinates = new double[this->dimension];
	for (int i = 0; i < this->dimension; i++)
	{
		coordinates[i] = this->coordinates[i] * lambda;
	}

	result.setCoordinates(coordinates);
	delete[] coordinates;

	return result;
}

double * Vector::getCoordinates() const
{
	return this->coordinates;
}

int Vector::getDimension() const
{
	return this->dimension;
}

void Vector::setCoordinates(double * vectors)
{
	delete[] this->coordinates;
	this->coordinates = new double[this->dimension];
	for (int i = 0; i < this->dimension; i++)
	{
		this->coordinates[i] = vectors[i];
	}
}
