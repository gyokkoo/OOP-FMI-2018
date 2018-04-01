#include <iostream>
#include "Vector.h"

std::istream& operator>>(std::istream & is, Vector& v)
{
	double temp;
	std::cout << "Enter X = ";
	is >> temp;
	v.setX(temp);
	std::cout << "Enter Y = ";
	is >> temp;
	v.setY(temp);
	std::cout << "Enter Z = ";
	is >> temp;	
	v.setZ(temp);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "{" << v.getX() << ", " << v.getY() << ", " << v.getZ() << " }";
	return os;
}

Vector operator*(double lambda, const Vector& v)
{
	Vector result;
	result.setX(lambda * v.getX());
	result.setY(lambda * v.getY());
	result.setZ(lambda * v.getZ());
	return result;
}


int main()
{
	Vector f;
	Vector b(1, 2);
	Vector a(1);
	Vector c(1, 2, 3);
	std::cout << "Enter vector:\n";
	std::cin >> f;
	std::cout << "Input vector = " << f << "\n";

	std::cout << "-------------------------\n";
	std::cout << "Vector a = " << a << "\n";
	std::cout << "Vector b = " << b << "\n";
	std::cout << "Vector c = " << c << "\n";
	
	std::cout << "Vector a + b + c = " << a + b + c << "\n";
	std::cout << "Vector a - b - c = " << a - b - c << "\n";
	std::cout << "Vector c * 5 = " << c * 5 << "\n";
	std::cout << "Vector -5 * c = " << 5 * c << "\n";

	std::cout << "Number b*c = " << b*c << "\n";

	Vector m = b ^ c;
	std::cout << "Vector b^c = " << m << "\n";
	// std::cout << "Vector b^c = " << b ^ c << "\n";
	return 0;
}