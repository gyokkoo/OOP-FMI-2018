#pragma once
#include <iostream>
#include "Employee.h"

class ITSpecialist : public Employee
{
public:
	ITSpecialist();
	ITSpecialist(const char* name, int experience, double salary, const char* project);
	ITSpecialist(const ITSpecialist& other);
	ITSpecialist& operator=(const ITSpecialist& rhs);
	~ITSpecialist();

	void setProject(const char* project);
	const char* getProject() const;

	void print() const;
private:
	char* project;
};