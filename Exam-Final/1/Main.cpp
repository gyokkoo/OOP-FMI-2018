#include <iostream>

#include "Const.h"
#include "Var.h"
#include "Sum.h"
#include "Product.h"

int main()
{
	Expression* five = new Const(5);
	five->print();
	std::cout << "\n";
	
	Expression* tenVar = new Var(10.0, "Ten");
	tenVar->print();
	std::cout << "\n";

	Expression* sum = new Sum(five, tenVar);
	sum->print();
	std::cout << "\n";

	Sum sumTwo(five, tenVar);
	Expression* copySum = new Sum(sumTwo);

	Expression* product = new Product(sum, five);
	product->print();
	std::cout << "\n";

	Product productTwo(five, tenVar);
	Expression* copyProduct = new Product(productTwo); // Tesing copy constructor
	copyProduct->print();
	std::cout << "\n";

	Expression* complexSum = new Sum(product, sum);
	complexSum->print();
	std::cout << "\n";

	delete five;
	delete tenVar;
	delete copySum;
	delete product;
	delete copyProduct;
	delete complexSum;

	return 0;
}