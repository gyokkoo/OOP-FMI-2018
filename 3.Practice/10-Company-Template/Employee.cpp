#include "Employee.h"

Employee::Employee(const char * name, long long UCN, Company* insurer, const char* jobTitle)
	: Person(name, UCN, insurer), jobTitle(nullptr)
{
	this->setJobTitle(jobTitle);
}

Employee::Employee(const Employee & other) : Person<Company>(other), jobTitle(nullptr)
{
	this->setJobTitle(jobTitle);
}

Employee & Employee::operator=(const Employee & rhs)
{
	if (this != &rhs)
	{
		Person<Company>::operator=(rhs);
		this->setJobTitle(rhs.jobTitle);
	}

	return *this;
}

Employee::~Employee()
{
	delete[] this->jobTitle;
}

void Employee::setJobTitle(const char * jobTitle)
{
	if (jobTitle == nullptr)
	{
		std::cout << "Invalid job title!\n";
		return;
	}

	int length = strlen(jobTitle) + 1;

	delete[] this->jobTitle;
	this->jobTitle = new char[length];

	strcpy_s(this->jobTitle, length, jobTitle);
}

const char * Employee::getJobTitle() const
{
	if (this->jobTitle == nullptr)
	{
		return "No Title!";
	}

	return this->jobTitle;
}

std::ostream & operator<<(std::ostream & os, const Employee & employee)
{
	os << employee.getName() << " "
		<< employee.getUCN() << " "
		<< *(employee.getInsurer()) << " "
		<< employee.getJobTitle() << "\n";

	return os;
}
