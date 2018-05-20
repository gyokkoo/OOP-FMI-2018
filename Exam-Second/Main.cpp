#include <iostream>

#include "House.h"

int main()
{
	Building building;
	// std::cout << building;

	Building buildingA(12, 90, 4);
	std::cout << buildingA;

	Building buildingB(12, 91, 4);
	std::cout << buildingB;

	if (buildingA < buildingB)
	{
		std::cout << "BuildingA is smaller than BuildingB by total area!\n";
	}
	else
	{
		std::cout << "BuildingA is bigger (or equal) than BuildingB by total area!\n";
	}

	House house;
	// std::cout << house;

	House houseA(4, 50, 3, 5, "Ivan Ivanov");
	std::cout << houseA;

	House houseB(2, 25, 2, 9, "Georgi Georgiev");
	std::cout << houseB;

	// Comparing by rooms
	if (houseA < houseB)
	{
		std::cout << "HouseA has less rooms than HouseB!\n";
	}
	else
	{
		std::cout << "HouseA has more or equal rooms than HouseB!\n";
	}

	// Comparing by total area
	if ((Building)houseA < (Building)houseB)
	{
		std::cout << "HouseA is smaller than HouseB by total area!\n";
	}
	else
	{
		std::cout << "HouseA is bigger than HouseB by total area!\n";
	}

	// Testing copyCtor and assignment operator
	House copyHouseA(houseA);
	std::cout << copyHouseA;

	house = copyHouseA;
	std::cout << house;

	// Change houseA ownerName
	houseA.setOwnerName("Jeko Jekov");
	std::cout << houseA << copyHouseA;

	return 0;
}