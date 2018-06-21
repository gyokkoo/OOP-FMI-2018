#pragma once
#include <iostream>
#include <vector>

#include "Constant.h"
#include "MathExpression.h"

template<typename T>
class Max : public MathExpression<T>
{
public:
	Max();
	Max(const Max<T>& other);
	Max<T>& operator=(const Max<T>& rhs);
	~Max();

	virtual MathExpression<T>* clone() const override;

	virtual T value() const override;

	virtual void addExpression(MathExpression<T>* expression);
private:
	void clear();
	void copyFrom(const Max<T>& other);
private:
	std::vector<MathExpression<T>*> expressions;
};

template<typename T>
inline Max<T>::Max()
{
}

template<typename T>
inline Max<T>::Max(const Max<T>& other)
{
	for (size_t i = 0; i < other.expressions.size(); i++)
	{
		this->expressions.push_back(other.expressions[i]->clone());
	}
}

template<typename T>
inline Max<T>& Max<T>::operator=(const Max<T>& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

template<typename T>
inline Max<T>::~Max()
{
	this->clear();
}

template<typename T>
inline MathExpression<T>* Max<T>::clone() const
{
	return new Max<T>(*this);
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
inline void Max<T>::addExpression(MathExpression<T>* expression)
{
	if (this->expressions.size() >= MAX_LENGTH)
	{
		std::cout << "Container is full!\n";
		return;
	}

	expressions.push_back(expression->clone());
}

template<typename T>
inline void Max<T>::clear()
{
	for (size_t i = 0; i < this->expressions.size(); i++)
	{
		delete this->expressions[i];
	}
}

template<typename T>
inline void Max<T>::copyFrom(const Max<T>& other)
{
	for (size_t i = 0; i < rhs.expressions.size(); i++)
	{
		this->expressions.push_back(rhs.expressions[i]->clone());
	}
}
