#pragma once

#include "MathExpression.h"

template<typename T>
class Prod : public MathExpression<T>
{
public:
	Prod(MathExpression<T>* first, MathExpression<T>* second);
	
	virtual MathExpression<T>* clone() const override;

	virtual T value() const override;

private:
	T val;
};

template<typename T>
inline Prod<T>::Prod(MathExpression<T>* first, MathExpression<T>* second)
{
	this->val = first->value() * second->value();
}

template<typename T>
inline T Prod<T>::value() const
{
	return this->val;
}

template<typename T>
inline MathExpression<T>* Prod<T>::clone() const
{
	return new Prod<T>(*this);
}
