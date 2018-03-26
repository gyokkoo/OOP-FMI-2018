#pragma once
#include "Point.h"

class Line
{
public:
	Line();

	Line(Point a, Point b, Color color = White);

	Line(const Line& line);

	~Line();

	void translate(double horizontal, double vertical);

	void print() const;

	Point getA() const;
	Point getB() const;
	Color getColor() const;

	void setA(Point a);
	void setB(Point b);
	void setColor(Color color);
private:
	Point a;
	Point b;
	Color color;
};