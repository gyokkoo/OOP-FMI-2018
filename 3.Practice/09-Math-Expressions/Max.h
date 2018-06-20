#pragma once
#include <iostream>
#include <vector>

#include "Constant.h"
#include "MathExpression.h"

const int MAX_LENGTH = 10;

template<typename T>
class Max : public MathExpression<T>
{
public:
	Max();

	virtual T value() const override;

	virtual void print() const override;

	virtual void addExpression(MathExpression<T>* expression) override;
private:
	std::vector<MathExpression<T>*> expressions;
};

template<typename T>
inline Max<T>::Max()
{
}

template<typename T>
inline T Max<T>::value() const
{
	T max = 0;
	for (size_t i = 0; i < this->expressions.size(); i++)
	{
	 	if (this->expressions[i]->value() > max)
	 	{
	 		max = this->expressions[i]->value();
	 	}
	}

	return max;
}

template<typename T>
inline void Max<T>::print() const
{
	std::cout << this->value() << "\n";
}

template<typename T>
inline void Max<T>::addExpression(MathExpression<T>* expression)
{
	if (this->expressions.size() >= MAX_LENGTH)
	{
		std::cout << "Container is full!\n";
		return;
	}

	expressions.push_back(expression);
}
