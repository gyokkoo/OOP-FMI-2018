#pragma once
#include "Expression.h"

class Const : public Expression
{
public:
	Const(double value);

	virtual Expression* clone() const override;

	virtual double value() const override;
	virtual void print() const override;
private:
	double val;
};