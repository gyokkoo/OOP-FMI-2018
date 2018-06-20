#pragma once

template<typename T>
class MathExpression
{
public:
	virtual T value() const = 0;

	virtual void print() const = 0;

	virtual void addExpression(MathExpression* expression)  = 0;
};
