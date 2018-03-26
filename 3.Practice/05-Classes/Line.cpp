#include <iostream>
#include "Line.h"

Line::Line() : a(), b(), color(White)
{
}

Line::Line(Point a, Point b, Color color)
{
	this->setA(a);
	this->setB(b);
	this->setColor(color);
}

Line::Line(const Line& line)
{
	this->a = line.a;
	this->b = line.b;
}

Line::~Line()
{
}

void Line::translate(double horizontal, double vertical)
{
	this->a.translate(horizontal, vertical);
	this->b.translate(horizontal, vertical);
}

void Line::print() const
{
	std::cout << "Line with 2 points: \n";
	this->a.print();
	this->b.print();
}

Color Line::getColor() const
{
	return this->color;
}

Point Line::getA() const
{
	return this->a;
}

void Line::setA(Point a)
{
	this->a = a;
}

Point Line::getB() const
{
	return this->b;
}

void Line::setB(Point b)
{
	this->b = b;
}

void Line::setColor(Color color)
{
	this->color = color;
}
