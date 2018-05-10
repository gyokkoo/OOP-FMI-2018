#pragma once
#include "ITSpecialist.h"

class Programmer : public ITSpecialist
{
public:
	Programmer();
	Programmer(const char* name, int experience, double salary, const char* project, const char* languages);
	virtual ~Programmer();
	virtual double work();

	const char* getLanguages() const;
	void setLanguages(const char* languages);

	virtual Employee* clone();

	virtual void print() const;
private:
	char languages[20];
};