#pragma once
#include "Company.h"
#include "Person.h"

class Employee : public Person<Company>
{
public:
	Employee(const char* name, long long UCN, Company* insurer, const char* jobTitle);
	Employee(const Employee& other);
	Employee& operator=(const Employee& rhs);
	~Employee();

	void setJobTitle(const char* jobTitle);

	const char* getJobTitle() const;
private:
	char* jobTitle;
};

std::ostream& operator<<(std::ostream& os, const Employee& employee);