#include <iostream>
#include "Vector.h"

Vector operator-(const Vector& a, const Vector& b)
{
	Vector result;
	result.setX(a.getX() - b.getX());
	result.setY(a.getY() - b.getY());
	result.setZ(a.getZ() - b.getZ());

	return result;
}

Vector operator*(const Vector& a, const Vector& b)
{
	Vector result;
	// Todo: Apply the formula
	return result;
}

std::istream& operator>>(std::istream & is, Vector& v)
{
	double t;
	is >> t;
	v.setX(t);
	is >> t;
	v.setY(t);
	is >> t;	
	v.setZ(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << v.getX() << " " << v.getY() << " " << v.getZ();
	return os;
}

int main()
{
	Vector f;
	Vector a(1);
	Vector b(1, 2);
	Vector c(1, 2, 3);
		
	// a.print();
	// b.print();
	// c.print();

	Vector m = a + b + c;
	Vector n = a - b - c;
	// m.print();
	// n.print();

	std::cin >> f;
	std::cout << f << "\n";
	return 0;
}