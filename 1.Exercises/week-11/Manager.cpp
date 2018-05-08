#include <iostream>
#include "Manager.h"

Manager::Manager() : Employee(), employeeCount(0)
{
}

Manager::Manager(const char* name, int experience, double salary, int employeeCount) : Employee(name, experience, salary)
{
	this->setEmployeeCount(employeeCount);
}

Manager::~Manager()
{
}

double Manager::work()
{
	double workPercentage = 0;
	if (this->getExperience() < 2 * 12)
	{
		workPercentage = 25;
	}
	else if (this->getExperience() > 4 * 12)
	{
		workPercentage = (this->getExperience() - 4 * 12) * 10;
	}

	return workPercentage;
}

void Manager::setEmployeeCount(int count)
{
	this->employeeCount = count;
}

int Manager::getEmployeeCount() const
{
	return this->employeeCount;
}

void Manager::print() const
{
	std::cout << "Manager: \n";
	Employee::print();
	std::cout << "----Employees: " << this->getEmployeeCount() << "\n";
}
