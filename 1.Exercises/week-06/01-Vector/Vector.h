#pragma once

class Vector
{
public:
	Vector(double x = 0, double y = 0, double z = 0);

	Vector operator+(const Vector& vector) const;
	Vector operator-(const Vector& vector) const;
	Vector operator*(double lambda) const;
	double operator*(const Vector& b) const;
	Vector operator^(const Vector& b) const;

	double getX() const;
	double getY() const;
	double getZ() const;

	void setX(double x);
	void setY(double y);
	void setZ(double z);
private:
	double x;
	double y;
	double z;
};