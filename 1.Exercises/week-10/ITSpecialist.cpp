#include "ITspecialist.h"
#include "Employee.h"

ITSpecialist::ITSpecialist() : Employee(), project(nullptr)
{
}

ITSpecialist::ITSpecialist(const char* name, int experience, double salary, const char* project) :
	Employee(name, experience, salary), project(nullptr)
{
	this->setProject(project);
}

ITSpecialist::ITSpecialist(const ITSpecialist& other) : Employee(other), project(nullptr)
{
	this->setProject(other.project);
}

ITSpecialist& ITSpecialist::operator=(const ITSpecialist& rhs)
{
	if (this != &rhs)
	{
		Employee::operator=(rhs);
		this->setProject(rhs.project);
	}

	return *this;
}

ITSpecialist::~ITSpecialist()
{
	delete[] this->project;
}

void ITSpecialist::setProject(const char * project)
{
	if (project == nullptr)
	{
		this->project = nullptr;
		return;
	}

	delete[] this->project;
	int length = strlen(project);
	this->project = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->project[i] = project[i];
	}
	this->project[length] = '\0';
}

const char* ITSpecialist::getProject() const
{
	if (this->project == nullptr)
	{
		return "No projects\n";
	}

	return this->project;
}

void ITSpecialist::print() const
{
	Employee::print();
	std::cout << "----Project: " << this->getProject() << "\n";
}
