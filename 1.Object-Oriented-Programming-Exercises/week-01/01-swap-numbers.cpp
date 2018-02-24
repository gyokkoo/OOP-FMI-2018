/**
*
* Solution to exercises
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <assert.h>

void swapViaReference(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	
	// Geek way: XOR Algorithm
	/*
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	*/
}

void swapViaPointers(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int a, int b)
{
	std::cout << "a = " << a << " b = " << b << "\n";
}

const int firstValue = 5;
const int secondValue = 10;

int main()
{
	int a = firstValue;
	int b = secondValue;

	print(a, b);

	swapViaReference(a, b);
	assert(a == secondValue);
	assert(b == firstValue);
	print(a, b);

	swapViaPointers(&a, &b);
	assert(a == firstValue);
	assert(b == secondValue);
	print(a, b);

	system("pause");
}
