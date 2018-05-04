#include <iostream>
#include "QA.h"

QA::QA() : ITSpecialist(), isManual(false)
{
}

QA::QA(const char * name, int experience, double salary, const char * project, bool isManual)
	: ITSpecialist(name, experience, salary, project)
{
	this->setIsManual(isManual);
}

void QA::setIsManual(bool isManual)
{
	this->isManual = isManual;
}

bool QA::getIsManual() const
{
	return this->isManual;
}

void QA::print() const
{
	std::cout << "QA specialist: \n";
	ITSpecialist::print();
	std::cout << "----Is manual testing? "
		<< (this->isManual ? "Yes" : "No") << "\n";
}
