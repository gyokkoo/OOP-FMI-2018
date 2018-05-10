#pragma once
#include "ITSpecialist.h"

class QA : public ITSpecialist
{
public:
	QA();
	QA(const char* name, int experience, double salary, const char* project, bool isManual);
	virtual ~QA();

	virtual double work();
	virtual Employee* clone();


	void setIsManual(bool isManual);
	bool getIsManual() const;

	virtual void print() const;
private:
	bool isManual;
};