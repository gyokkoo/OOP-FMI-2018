#pragma once
#include "Point.h"

class Rectangle
{
public:
	Rectangle();
	
	Rectangle(Point point, double height, double width, Color color = White);

	Rectangle(const Rectangle& rectangle);

	~Rectangle();

	void translate(double horizontal, double vertical);
	
	void print() const;

	Point getPoint() const;
	double getHeight() const;
	double getWidth() const;
	Color getColor() const;

	void setPoint(Point point);
	void setHeight(double height);
	void setWidth(double width);
	void setColor(Color color);
private:
	Point point;
	Color color;
	double height;
	double width;
};