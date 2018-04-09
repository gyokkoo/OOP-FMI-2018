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
	double operator[](int index) const;
	
	double* getCoordinates() const;
	int getDimension() const;

	void setCoordinates(double* coordinates);
	void setDimension(int dimension);
private:
	double* coordinates;
	int dimension;
};

std::ostream& operator<<(std::ostream& os, const Vector& vector);

std::istream& operator>>(std::istream& is, Vector& vector);
