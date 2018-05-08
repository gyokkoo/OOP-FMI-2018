#pragma once
#include <vector>

#include "Employee.h"
#include "Manager.h"

class Company
{
public:
	Company();
	Company(const Company& other);
	Company& operator=(const Company& rhs);
	~Company();

	double getTotalWork() const;

	void setBoss(Manager* boss);
	 
	void operator+=(Employee* newEmployee);
	void addEmployee(Employee* newEmployee);
	void removeEmployee(int index);

	double getTotalExpenses() const;
	double getAverageSalary() const;
	void removeNewEmployees();

	void printAll() const;
private:
	void copyFrom(const Company& other);
	void clear();
private:
	Manager* boss;
	std::vector<Employee*> employees;
};