#include <iostream>
#include "House.h"

int main()
{
	Building building(30, 650.43, "ul. \"8-mi dekemvri\"");
	building.print();
	std::cout << "----------\n";

	House house(5, 125.34, "ul. Hirsto Botev 123", 2, "Ivan Ivanov");
	house.print();
	std::cout << "----------\n";

	return 0;
}