#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"

int main()
{
	Point a;
	Point b(1.5, 2.5);
	a.translate(1, 2);
	a.print();
	b.print();
	
	Rectangle firstRectangle;
	Rectangle secondRectangle(a, 5, 4, Blue);
	firstRectangle.translate(1, 0);
	firstRectangle.setHeight(1);
	firstRectangle.setWidth(2);
	firstRectangle.print();
	secondRectangle.print();

	Line firstLine;
	Line secondLine(a, b, Red);
	firstLine.translate(-1, -4);
	firstLine.print();
	secondLine.print();

	Circle firstCircle;
	Circle secondCirlce(a, 5.5, Black);
	firstCircle.translate(1.5, -0.5);
	firstCircle.setRadius(5);
	firstCircle.print();
	secondCirlce.print();

	return 0;
}