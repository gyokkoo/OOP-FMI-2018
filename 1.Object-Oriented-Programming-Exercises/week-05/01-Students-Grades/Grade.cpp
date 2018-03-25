#include "Grade.h"
#include <iostream>

Grade::Grade() : grade(0)
{
	this->setSubject("N/A");
}

Grade::Grade(const char* subject, double grade)
{
	this->setSubject(subject);
	this->setGrade(grade);
}

Grade::Grade(const Grade& grade)
{
	this->setSubject(grade.getSubject());
	this->setGrade(grade.getGrade());
	std::cout << "Grade copy constructor!\n";
}

void Grade::setGrade(double grade)
{
	if (grade < 2 || grade > 6)
	{
		std::cout << "Invalid grade!\n";
		this->grade = 0;
		return;
	}

	this->grade = grade;
}

void Grade::setSubject(const char* subject)
{
	strcpy_s(this->subject, subject);
}

double Grade::getGrade() const
{
	return this->grade;
}

const char* Grade::getSubject() const
{
	return this->subject;
}

void Grade::print() const
{
	std::cout << this->getSubject() << " - " << this->getGrade() << "\n";
}