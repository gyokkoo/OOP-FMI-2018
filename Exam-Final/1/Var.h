#pragma once
#include "Expression.h"

class Var : public Expression
{
public:
	Var();
	Var(double value, const char* name);
	Var(const Var& other);
	Var& operator=(const Var& rhs);
	~Var();

	virtual Expression* clone() const override;

	void setName(const char* name);
	void setValue(double value);

	const char* getName() const;
	virtual double value() const override;
	virtual void print() const override;
private:
	double val;
	char* name;
};