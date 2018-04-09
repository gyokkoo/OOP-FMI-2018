#include <iostream>
#include "Vector.h"

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

	std::cout << "Number b*c = " << b * c << "\n";

	std::cout << "Vector b^c = " << (b ^ c) << "\n";

	return 0;
}