#pragma once

class Point
{
public:
	Point();
	Point(double x, double y, const char* name);
	Point(const Point& point);
	Point& operator=(const Point& rhs);
	~Point();

	double getX() const;
	double getY() const;
	const char* getName() const;

	void setX(double x);
	void setY(double y);
	void setName(const char* name);

	double getDistance(const Point& p);
	void translate(double dx, double dy);

	void print() const;
private:
	double x;
	double y;
	char* name;
};