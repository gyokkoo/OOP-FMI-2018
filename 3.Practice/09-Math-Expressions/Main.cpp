#include <iostream>

#include "Constant.h"
#include "Max.h"

int main()
{
	MathExpression<int>* numberFive = new Constant<int>(5);
	MathExpression<int>* numberTen = new Constant<int>(10);

	MathExpression<int>* max = new Max<int>();
	max->addExpression(numberFive);
	max->addExpression(numberTen);

	MathExpression<int>* maxTwo = new Max<int>();
	maxTwo->addExpression(new Constant<int>(55));
	maxTwo->addExpression(new Constant<int>(110));

	max->addExpression(maxTwo);
	max->print();

	return 0;
}