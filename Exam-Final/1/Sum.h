#pragma once
#include "Expression.h"

class Sum : public Expression
{
public:
	Sum(Expression* first, Expression* second);
	Sum(const Sum& other);
	Sum& operator=(const Sum& rhs);
	~Sum();

	virtual Expression* clone() const override;

	virtual double value() const override;
	virtual void print() const override;
private:
	Expression* first;
	Expression* second;
};