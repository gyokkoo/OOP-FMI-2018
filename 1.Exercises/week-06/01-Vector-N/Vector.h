#pragma once

class Vector
{
public:
	Vector();
	Vector(int dimension);
	Vector(double* coordinates, int dimension);
	Vector(const Vector& other);
	~Vector();
	Vector& operator=(const Vector& vector);

	Vector operator+(const Vector& vector);
	Vector operator-(const Vector& vector);
	Vector operator*(double lambda);

	double* getCoordinates() const;
	int getDimension() const;

	void setCoordinates(double* coordinates);
private:
	double* coordinates;
	int dimension;
};