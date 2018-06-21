#include <iostream>

#include "Average.h"
#include "Constant.h"
#include "Max.h"
#include "Sum.h"
#include "Prod.h"

int main()
{
	MathExpression<int>* numberFive = new Constant<int>(5);
	MathExpression<int>* numberTen = new Constant<int>(10);

	Max<int>* max = new Max<int>();
	max->addExpression(numberFive);
	max->addExpression(numberTen);
	max->print();

	Average<int>* average = new Average<int>();
	average->addExpression(numberFive);
	average->addExpression(numberTen);
	average->print();

	Sum<int>* sum = new Sum<int>(max, average);
	sum->print();

	Prod<int>* product = new Prod<int>(max, average);
	product->print();

	delete numberFive;
	delete numberTen;
	delete average;
	delete sum;
	delete product;
	
	return 0;
}