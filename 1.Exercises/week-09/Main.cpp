#include <iostream>
#include "House.h"

House* getLargestHouse(House* houses, int length)
{
	double largest = 0;
	double current = 0;
	House* largestHouse = nullptr;
	for (int i = 0; i < length; i++)
	{
		current = houses[i].getHeight() / houses[i].getStoreys();
		if (current > largest)
		{
			largestHouse = &houses[i];
			largest = current;
		}
	}

	return largestHouse;
}

int main()
{
	Building building(30, 650.43, "ul. \"8-mi dekemvri\"");
	building.print();
	std::cout << "----------\n";

	House house(5, 125.34, "ul. Hirsto Botev 123", 2, "Ivan Ivanov");
	house.print();
	std::cout << "----------\n";

	House houseTwo(10, 154, "ul. Hirsto Botev 124", 3, "Ivan Petrov");
	House houseThree(10, 165, "ul. Hirsto Botev 124", 4, "Ivan Petrov");

	House houses[3];
	houses[0] = house;
	houses[1] = houseTwo;
	houses[2] = houseThree;

	std::cout << "Largest house:\n";
	House* largest = getLargestHouse(houses, 3);
	largest->print();

	// Building inputBuilding;
	// inputBuilding.read();
	// inputBuilding.print();

	House inputHouse;
	inputHouse.read();
	inputHouse.print();

	return 0;
}