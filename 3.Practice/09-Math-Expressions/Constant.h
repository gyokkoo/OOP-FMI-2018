#pragma once
#include "MathExpression.h"

template<typename T>
class Constant : public MathExpression<T>
{
public:
	Constant(const T& value);

	virtual T value() const override;

	virtual void print() const override;

	virtual void addExpression(MathExpression<T>* expression);
private:
	T v;
};

template<typename T>
inline Constant<T>::Constant(const T & value)
{
	this->v = value;
}

template<typename T>
inline T Constant<T>::value() const
{
	return this->v;
}

template<typename T>
inline void Constant<T>::print() const
{
	std::cout << this->value() << "\n";
}

template<typename T>
inline void Constant<T>::addExpression(MathExpression<T>* expression)
{
	this->v = expression->value();
}
