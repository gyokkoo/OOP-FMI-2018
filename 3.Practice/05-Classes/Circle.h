#pragma once
#include "Point.h"

class Circle
{
public:
	Circle();

	Circle(Point center, double radius, Color color = White);

	Circle(const Circle& circle);

	~Circle();

	void translate(double horizontal, double vertical);

	void print() const;

	Point getCenter() const;
	double getRadius() const;
	Color getColor() const;

	void setCenter(Point center);
	void setRadius(double radius);
	void setColor(Color color);
private:
	Point center;
	double radius;
	Color color;
};