#include "Student.h"
#include <string.h>
#include <iostream>

Student::Student() : fn(0), grades(nullptr), gradesCount(0)
{
	this->setName("N/A");
}

Student::Student(int fn, const char* name, int gradesCount)
{
	this->setFn(fn);
	this->setName(name);
	this->gradesCount = gradesCount;
	this->grades = new Grade[gradesCount];
}

Student::~Student()
{
	delete[] this->grades;
}

void Student::setFn(int fn)
{
	if (fn < 0)
	{
		std::cout << "Wrong fn!\n";
		this->fn = 0;
		return;
	}

	this->fn = fn;
}

int Student::getFn() const
{
	return this->fn;
}

void Student::setName(const char* name)
{
	strcpy_s(this->name, name);
}

const char* Student::getName() const
{
	return this-> name;
}

void Student::print() const
{
	std::cout << this->getName() << " - " << this->getFn() << "\n";
}