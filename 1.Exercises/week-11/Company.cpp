#include <iostream>
#include "Company.h"

Company::Company()
{
	this->boss = nullptr;
}

Company::Company(const Company& other)
{
	this->copyFrom(other);
}

Company& Company::operator=(const Company& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

Company::~Company()
{
	this->clear();
}

double Company::getTotalWork() const
{
	double totalWork = 0;
	int size = this->employees.size();
	for (int i = 0; i < size; i++)
	{
		totalWork += this->employees[i]->work();
	}

	totalWork += totalWork * (this->boss->work() / 100);

	return totalWork;
}

void Company::setBoss(Manager* boss)
{
	Manager* bossCopy = boss;
	this->boss = bossCopy;
}

void Company::operator+=(Employee* newEmployee)
{
	addEmployee(newEmployee);
}

void Company::addEmployee(Employee* newEmployee)
{
	this->employees.push_back(newEmployee);
}

void Company::removeEmployee(int index)
{
	int size = this->employees.size();
	if (index < 0 || index >= size)
	{
		std::cout << "Invalid index!\n";
		return;
	}

	Employee* employeeToRemove = this->employees[index];
	this->employees.erase(this->employees.begin() + index);
	
	delete employeeToRemove;
}

double Company::getTotalExpenses() const
{
	double total = 0;
	int size = this->employees.size();
	for (int i = 0; i < size; ++i)
	{
		total += this->employees[i]->getSalary();
	}

	return total;
}

double Company::getAverageSalary() const
{
	return this->getTotalExpenses() / this->employees.size();
}

void Company::removeNewEmployees()
{
	int size = this->employees.size();
	for (int i = 0; i < size; ++i)
	{
		if (this->employees[i]->getExperience() < 3)
		{
			this->removeEmployee(i);
			i--;
		}
	}
}

void Company::printAll() const
{
	if (this->employees.size() == 0)
	{
		std::cout << "No employees!\n";
		return;
	}
	
	if (this->boss == nullptr)
	{
		std::cout << "No boss!\n";
	}
	else 
	{
		this->boss->print();
	}
	std::cout << "\nAll employees in the company:\n";
	int size = this->employees.size();
	for (int i = 0; i < size; ++i)
	{
		this->employees[i]->print();
		std::cout << "______________________\n";
	}
}

void Company::clear()
{
	delete[] this->boss;
	this->boss = nullptr;
	int size = this->employees.size();
	for (int i = 0; i < size; i++)
	{
		delete employees[i];
	}
}

void Company::copyFrom(const Company& other)
{
	this->boss = new Manager(*other.boss);
	// copy container
	std::vector<Employee*> newEmployees;
	int size = other.employees.size();
	for (int i = 0; i < size; ++i)
	{
		Employee* oldEmployee = other.employees[i];
		Employee* newEmployee = oldEmployee->clone();
		newEmployees.push_back(newEmployee);
	}

	this->employees = newEmployees;
}
