#pragma once

enum Color
{
	Red,
	Green,
	Blue,
	White,
	Black,
};

class Point
{
public:
	Point();

	Point(double x, double y);

	Point(const Point& point);

	~Point();

	void translate(double horizontal, double vertical);
	
	void print() const;

	double getX() const;
	double getY() const;

	void setX(double x);
	void setY(double y);
private:
	double x;
	double y;
};