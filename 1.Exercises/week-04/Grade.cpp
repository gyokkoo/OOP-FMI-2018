#include "Grade.h"
#include <iostream>

Grade::Grade() : grade(0)
{
	this->setSubject("N/A");
}

Grade::Grade(const char* subject, int grade)
{
	this->setSubject(subject);
	this->setGrade(grade);
}

void Grade::setGrade(int grade)
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

int Grade::getGrade() const
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