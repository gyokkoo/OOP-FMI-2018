#pragma once

#include "Employee.h"
#include "Manager.h"

const int INITIAL_CAPACITY = 2;

class Company
{
public:
	Company(int capacity = INITIAL_CAPACITY);
	Company(const Company& other);
	Company& operator=(const Company& rhs);
	~Company();

	double getTotalWork() const;

	void setBoss(Manager* boss);
	
	void operator+=(const Employee& newEmployee);
	
	void addEmployee(const Employee& newEmployee);
	void removeEmployee(int index);

	double getTotalExpenses() const;
	double getAverageSalary() const;
	void removeNewEmployees();

	void printAll() const;
private:
	void clear();
	void copyFrom(const Company& other);
	void resize(int newCapacity);
	void allocate(int count);
private:
	Manager* boss;
	Employee* employees;
	int count;
	int capacity;
};