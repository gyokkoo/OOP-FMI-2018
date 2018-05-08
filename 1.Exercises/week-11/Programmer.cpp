#include "Programmer.h"
#include <cstring>

Programmer::Programmer() : ITSpecialist(), languages("No languages")
{
}

Programmer::Programmer(const char * name, int experience, double salary, const char * project, const char * languages)
	: ITSpecialist(name, experience, salary, project)
{
	this->setLanguages(languages);
}

Programmer::~Programmer()
{
}

double Programmer::work()
{
	double moneyPerMonth = 75;
	double usefulness = this->getUsefulness(moneyPerMonth);
	std::cout << "Programmer " << this->getName() << " usefulness ~ " << usefulness << "\n";
	return usefulness;
}

const char* Programmer::getLanguages() const
{
	return this->languages;
}

void Programmer::setLanguages(const char* languages)
{
	int length = strlen(languages);
	for (int i = 0; i < length; i++)
	{
		this->languages[i] = languages[i];
	}
	this->languages[length] = '\0';
}

void Programmer::print() const
{
	std::cout << "Programmer: \n";
	ITSpecialist::print();
	std::cout << "----Languages:" << this->getLanguages() << "\n";
}
