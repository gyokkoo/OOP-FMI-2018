#pragma once
#include "Expression.h"

class Product : public Expression
{
public:
	Product(Expression* first, Expression* second);
	Product(const Product& other);
	Product& operator=(const Product& rhs);
	~Product();

	virtual Expression* clone() const override;

	virtual double value() const override;
	virtual void print() const override;
private:
	Expression* first;
	Expression* second;
};