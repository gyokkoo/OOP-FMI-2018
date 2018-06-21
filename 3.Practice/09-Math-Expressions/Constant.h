#pragma once
#include "MathExpression.h"

template<typename T>
class Constant : public MathExpression<T>
{
public:
	Constant(const T& value);

	virtual MathExpression<T>* clone() const override;

	virtual T value() const override;
private:
	T v;
};

template<typename T>
inline MathExpression<T>* Constant<T>::clone() const
{
	return new Constant<T>(*this);
}

template<typename T>
inline Constant<T>::Constant(const T& value)
{
	this->v = value;
}

template<typename T>
inline T Constant<T>::value() const
{
	return this->v;
}