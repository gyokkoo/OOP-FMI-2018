#pragma once
#include "ITSpecialist.h"

class QA : public ITSpecialist
{
public:
	QA();
	QA(const char* name, int experience, double salary, const char* project, bool isManual);

	void setIsManual(bool isManual);
	bool getIsManual() const;

	void print() const;
private:
	bool isManual;
};