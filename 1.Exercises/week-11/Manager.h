#pragma once
#include "Employee.h"

class Manager : public Employee
{
public:
	Manager();
	Manager(const char* name, int experience, double salary, int employeeCount);

	void setEmployeeCount(int count);
	int getEmployeeCount() const;

	void print() const;
private:
	int employeeCount;
};