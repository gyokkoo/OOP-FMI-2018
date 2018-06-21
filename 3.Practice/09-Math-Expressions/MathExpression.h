#pragma once

template<typename T>
class MathExpression
{
public:
	virtual ~MathExpression();
	
	virtual MathExpression<T>* clone() const = 0;

	virtual T value() const = 0;

	virtual void print() const;
};

template<typename T>
inline MathExpression<T>::~MathExpression()
{
}

template<typename T>
inline void MathExpression<T>::print() const
{
	std::cout << this->value() << "\n";
}
