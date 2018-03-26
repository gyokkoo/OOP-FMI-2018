#include <iostream>
#include "Point.h"

Point::Point() : x(0), y(0)
{
}

Point::Point(double x, double y)
{
	this->setX(x);
	this->setY(y);
}

Point::Point(const Point& point)
{
	this->x = point.x;
	this->y = point.y;
}

Point::~Point()
{
}

void Point::translate(double horizontal, double vertical)
{
	this->setX(this->x + horizontal);
	this->setY(this->y + vertical);
}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

void Point::print() const
{
	std::cout << " {" << this->x << ", " << this->y << " }" << "\n";
}

