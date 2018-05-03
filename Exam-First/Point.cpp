#include <iostream>
#include <cstring>
#include "Point.h"

Point::Point() : x(0.0), y(0.0), name(nullptr)
{
}

Point::Point(double x, double y, const char* name): name(nullptr)
{
	this->setX(x);
	this->setY(y);
	this->setName(name);
}

Point::Point(const Point& point): name(nullptr)
{
	this->setX(point.x);
	this->setY(point.y);
	this->setName(point.name);
}

Point & Point::operator=(const Point & rhs)
{
	if (this != &rhs)
	{
		this->setX(rhs.x);
		this->setY(rhs.y);
		this->setName(rhs.name);
	}

	return *this;
}

Point::~Point()
{
	delete[] this->name;
}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

const char * Point::getName() const
{
	if (this == nullptr)
	{
		return "No name!\n";
	}

	return this->name;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

void Point::setName(const char* name)
{
	delete[] this->name;
	int length = strlen(name);
	this->name = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}
	this->name[length] = '\0';
}

double Point::getDistance(const Point & p)
{
	double dx = this->x - p.x;
	double dy = this->y - p.y;
	return sqrt(dx * dx + dy * dy);
}

void Point::translate(double dx, double dy)
{
	this->setX(this->x + dx);
	this->setY(this->y + dy);
}

void Point::print() const
{
	std::cout
		<< this->getName()
		<< "(" << this->getX()
		<< "," << this->getY() << ")\n";
}
