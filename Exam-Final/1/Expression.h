#pragma once

class Expression
{
public:
	virtual ~Expression() 
	{
	}

	virtual Expression* clone() const = 0;

	virtual double value() const = 0;
	virtual void print() const = 0;
};