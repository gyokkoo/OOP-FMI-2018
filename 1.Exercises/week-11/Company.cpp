#include <iostream>
#include "Company.h"

Company::Company(int capacity)
{
	this->allocate(capacity);
	this->capacity = capacity;
	this->count = 0;
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
	for (int i = 0; i < this->count; i++)
	{
		totalWork += this->employees[i].work();
	}

	if (this->boss->getExperience() < 2)
	{
		totalWork = totalWork * 0.25;
	}
	else if (this->boss->getExperience() > 4)
	{
		totalWork = totalWork * (this->boss->getExperience() - 4) * 0.1;
	}

	return totalWork;
}

void Company::setBoss(Manager* boss)
{
	Manager* bossCopy(boss);
	this->boss = bossCopy;
}

void Company::operator+=(const Employee& newEmployee)
{
	addEmployee(newEmployee);
}

void Company::addEmployee(const Employee& newEmployee)
{
	if (this->count >= this->capacity)
	{
		this->resize(this->count * 2);
	}

	this->employees[this->count] = newEmployee;
	this->count++;
}

void Company::removeEmployee(int index)
{
	if (index < 0 || index >= this->count)
	{
		std::cout << "Invalid index!\n";
		return;
	}

	this->count--;
	for (int i = index; i < this->count; ++i)
	{
		this->employees[i] = this->employees[i + 1];
	}
}

double Company::getTotalExpenses() const
{
	double total = 0;
	for (int i = 0; i < this->count; ++i)
	{
		total += this->employees[i].getSalary();
	}

	return total;
}

double Company::getAverageSalary() const
{
	return this->getTotalExpenses() / this->count;
}

void Company::removeNewEmployees()
{
	for (int i = 0; i < this->count; ++i)
	{
		if (this->employees[i].getExperience() < 3)
		{
			this->removeEmployee(i);
			i--;
		}
	}
}

void Company::printAll() const
{
	if (this->count == 0)
	{
		std::cout << "No employees!\n";
		return;
	}

	std::cout << "All employees in the company:\n";
	for (int i = 0; i < this->count; ++i)
	{
		this->employees[i].print();
		std::cout << "______________________\n";
	}
}

void Company::clear()
{
	delete[] this->employees;
	this->employees = nullptr;
	this->capacity = 0;
	this->count = 0;
}

void Company::copyFrom(const Company& other)
{
	this->capacity = other.capacity;
	this->count = other.count;
	this->allocate(other.capacity);
	for (int i = 0; i < other.count; ++i)
	{
		this->employees[i] = other.employees[i];
	}
}

void Company::resize(int newCapacity)
{
	Employee* temp = this->employees;
	this->allocate(newCapacity);
	this->capacity = newCapacity;
	for (int i = 0; i < this->count; ++i)
	{
		this->employees[i] = temp[i];
	}
	delete[] temp;
}

void Company::allocate(int count)
{
	this->employees = new Employee[count];
}