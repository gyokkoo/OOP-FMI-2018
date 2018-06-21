#pragma once

#include "MathExpression.h"

template<typename T>
class Sum : public MathExpression<T>
{
public:
	Sum(MathExpression<T>* first, MathExpression<T>* second);

	virtual MathExpression<T>* clone() const override;

	T value() const;
private:
	T val;
};

template<typename T>
inline Sum<T>::Sum(MathExpression<T>* first, MathExpression<T>* second)
{
	this->val = first->value() + second->value();
}

template<typename T>
inline T Sum<T>::value() const
{
	return this->val;
}

template<typename T>
inline MathExpression<T>* Sum<T>::clone() const
{
	return new Sum(*this);
}
