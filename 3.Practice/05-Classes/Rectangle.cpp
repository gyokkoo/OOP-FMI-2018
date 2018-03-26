#include <iostream>
#include "Rectangle.h"
Rectangle::Rectangle() : point(0.0, 0.0), height(0), width(0), color(White)
{
}

Rectangle::Rectangle(Point p, double height, double width, Color color)
{
	this->setPoint(p);
	this->setHeight(height);
	this->setWidth(width);
	this->setColor(color);
}

Rectangle::Rectangle(const Rectangle & rectangle)
{
	this->point = rectangle.point;
	this->height = rectangle.height;
	this->width = rectangle.width;
	this->color = rectangle.color;
}

Rectangle::~Rectangle()
{
}

void Rectangle::translate(double horizontal, double vertical)
{
	this->point.translate(horizontal, vertical);
}

Point Rectangle::getPoint() const
{
	return this->point;
}

double Rectangle::getHeight() const
{
	return this->height;
}

void Rectangle::setPoint(Point point)
{
	this->point = point;
}

void Rectangle::setHeight(double height)
{
	this->height = height;
}

double Rectangle::getWidth() const
{
	return this->width;
}

void Rectangle::setWidth(double width)
{
	this->width = width;
}

Color Rectangle::getColor() const
{
	return this->color;
}

void Rectangle::setColor(Color color)
{
	this->color = color;
}

void Rectangle::print() const
{
	std::cout << "Rectangle with point, height and width:\n";
	this->point.print();
	std::cout << "Height: " << this->height << "\n";
	std::cout << "Width: " << this->width << "\n";
}
