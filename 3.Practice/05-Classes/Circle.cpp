#include "Circle.h"
#include <iostream>

Circle::Circle() : center(), radius(0.0), color(White)
{
}

Circle::Circle(Point center, double radius, Color color)
{
	this->setCenter(center);
	this->setRadius(radius);
	this->setColor(color);
}

Circle::Circle(const Circle & circle)
{
	this->center = circle.center;
	this->radius = circle.radius;
	this->color = circle.color;
}

Circle::~Circle()
{
}

void Circle::translate(double horizontal, double vertical)
{
	this->center.translate(horizontal, vertical);
}

void Circle::print() const
{
	std::cout << "Circle with center point and radius: \n";
	this->center.print();
	std::cout << "Radius: " << this->radius << "\n";
}

Point Circle::getCenter() const
{
	return this->center;
}

void Circle::setCenter(Point center)
{
	this->center = center;
}

double Circle::getRadius() const
{
	return this->radius;
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

Color Circle::getColor() const
{
	return this->color;
}

void Circle::setColor(Color color)
{
	this->color = color;
}
