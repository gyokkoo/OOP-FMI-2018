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
	virtual ~ITSpecialist();

	void setProject(const char* project);
	const char* getProject() const;

	virtual double getUsefulness(double moneyPerMonth);

	void print() const;
private:
	char* project;
};