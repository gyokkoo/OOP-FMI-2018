#pragma once
#include <vector>
#include "MathExpression.h"

template<typename T>
class Average : public MathExpression<T>
{
public:
	Average();
	Average(const Average<T>& other);
	Average<T>& operator=(const Average<T>& rhs);
	~Average();

	virtual MathExpression<T>* clone() const override;

	virtual T value() const override;

	virtual void addExpression(MathExpression<T>* expression);
private:
	void clear();
	void copyFrom(const Average<T>& other);
private:
	std::vector<MathExpression<T>*> expressions;
};

template<typename T>
inline Average<T>::Average()
{
}

template<typename T>
inline Average<T>::Average(const Average<T>& other)
{
	this->copyFrom(other);
}

template<typename T>
inline Average<T>& Average<T>::operator=(const Average<T>& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copyFrom(rhs);
	}

	return *this;
}

template<typename T>
inline Average<T>::~Average()
{
	this->clear();
}

template<typename T>
inline MathExpression<T>* Average<T>::clone() const
{
	return new Average<T>(*this);
}

template<typename T>
inline T Average<T>::value() const
{
	if (this->expressions.size() == 0)
	{
		return 0;
	}
	
	T sum = 0;
	for (size_t i = 0; i < this->expressions.size(); i++)
	{
		sum += this->expressions[i]->value();
	}

	return sum / this->expressions.size();
}

template<typename T>
inline void Average<T>::addExpression(MathExpression<T>* expression)
{
	if (this->expressions.size() >= MAX_LENGTH)
	{
		std::cout << "Container is full!\n";
		return;
	}

	this->expressions.push_back(expression->clone());
}

template<typename T>
inline void Average<T>::clear()
{
	for (size_t i = 0; i < this->expressions.size(); i++)
	{
		delete this->expressions[i];
	}
}

template<typename T>
inline void Average<T>::copyFrom(const Average<T>& other)
{
	for (size_t i = 0; i < other.expressions.size(); i++)
	{
		this->expressions.push_back(other.expressions[i]->clone());
	}
}
