#include <iostream>
#include "Vector.h"

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
	double* coordinates = vector.getCoordinates();
	int size = vector.getDimension();
	for (int i = 0; i < size; i++)
	{
		os << coordinates[i] << " ";
	}
	os << "\n";

	return os;
}

int main()
{
	double* firstCoordinates = new double[3];
	double* secondCoordinates = new double[3];

	firstCoordinates[0] = 3;
	firstCoordinates[1] = 2;
	firstCoordinates[2] = 5;
	secondCoordinates[0] = 7;
	secondCoordinates[1] = 11;
	secondCoordinates[2] = 14;

	Vector vectorA(firstCoordinates, 3);
	Vector vectorB(secondCoordinates, 3);

	std::cout << "Vector a = " << vectorA;
	std::cout << "Vector b = " << vectorB;
	std::cout << "Vector a - b = " << vectorA - vectorB;
	std::cout << "Vector b - a = " << vectorB - vectorA;
	std::cout << "Vector a + b = " << vectorA + vectorB;
	std::cout << "Vector a * 5 = " << vectorA * 5;

	delete[] firstCoordinates;
	delete[] secondCoordinates;

	return 0;
}