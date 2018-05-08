#include <iostream>
#include <cstring>
#include "Employee.h"

Employee::Employee() : name(nullptr), experience(0), salary(0)
{
}

Employee::Employee(const char* name, int experience, double salary) : name(nullptr)
{
	this->setName(name);
	this->setExperience(experience);
	this->setSalary(salary);
}

Employee::Employee(const Employee& emp) : name(nullptr)
{
	this->setName(emp.name);
	this->setExperience(emp.experience);
	this->setSalary(emp.salary);
}

Employee& Employee::operator=(const Employee& rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.name);
		this->setExperience(rhs.experience);
		this->setSalary(rhs.salary);
	}

	return *this;
}

Employee::~Employee()
{
	delete[] this->name;
}

double Employee::work()
{
	std::cout << "Employee class work!\n";
	return 0.0;
}

const char* Employee::getName() const
{
	return this->name;
}

int Employee::getExperience() const
{
	return this->experience;
}

double Employee::getSalary() const
{
	return this->salary;
}

void Employee::setName(const char * name)
{
	if (name == nullptr)
	{
		this->name = nullptr;
		return;
	}

	delete[] this->name;
	int length = strlen(name);
	this->name = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->name[i] = name[i];
	}
	this->name[length] = '\0';
}

void Employee::setExperience(int experience)
{
	this->experience = experience;
}

void Employee::setSalary(double salary)
{
	this->salary = salary;
}

void Employee::print() const
{
	std::cout << "----Name: " << this->getName() << "\n";
	std::cout << "----Experience: " << this->getExperience() << " months\n";
	std::cout << "----Salary: " << this->getSalary() << " leva\n";
}

double Employee::getUsefulness(double moneyPerMonth)
{
	if (this->getExperience() < 6)
	{
		return 0;
	}

	double usefulness = this->getExperience() * moneyPerMonth;
	if (this->getSalary() < 0.5 * usefulness)
	{
		usefulness = usefulness * 0.7;
	}

	return usefulness;
}
