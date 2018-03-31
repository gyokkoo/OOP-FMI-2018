#pragma once

class Vector
{
public:
	Vector(double x = 0, double y = 0, double z = 0);

	Vector add(const Vector& vector) const;

	Vector operator+(const Vector& vector) const;

	void print() const;

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	double getX() const;
	double getY() const;
	double getZ() const;

private:
	double x;
	double y;
	double z;
};