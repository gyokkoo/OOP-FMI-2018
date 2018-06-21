#include <iostream>

#include "Company.h"
#include "Person.h"
#include "Employee.h"

int main()
{
	Company company("Company OOD", 133440432);

	Employee ivan("Ivan Ivanov", 9612325423, &company, "Junior");

	std::cout << ivan << "\n";

	Employee ivanCopy(ivan);
	std::cout << ivanCopy << "\n";
	
	Employee pesho("Pesho Peshev", 3343434343, &company, "Senior");
	ivanCopy = pesho;
	std::cout << ivanCopy << "\n";

	return 0;
}