#pragma once
#include "ITSpecialist.h"

class Programmer : public ITSpecialist
{
public:
	Programmer();
	Programmer(const char* name, int experience, double salary, const char* project, const char* languages);

	const char* getLanguages() const;
	void setLanguages(const char* languages);

	void print() const;
private:
	char languages[20];
};