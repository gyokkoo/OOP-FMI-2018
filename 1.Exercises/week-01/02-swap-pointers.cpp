/**
*
* Solution to exercises
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <assert.h>

void swapPointers(int*& a, int*& b)
{
	int *temp = a;
	a = b;
	b = temp;
}

void print(int a, int b)
{
	std::cout << "a = " << a << " b = " << b << "\n";
}

void printPointers(int* pa, int* pb)
{
    // Prints pointer in the console
	std::cout << "pa = " << static_cast<void*>(pa) << "\n";
	std::cout << "pb = " << static_cast<void*>(pb) << "\n";
}

const int firstValue = 5;
const int secondValue = 10;

int main()
{
	// The program swap pointers not values

	int a = firstValue;
	int b = secondValue;
	int* pa = &a;
	int* pb = &b;

	print(a, b);
	printPointers(pa, pb);

	swapPointers(pa, pb);
	std::cout << "After swapping: \n";
	print(a, b);
	printPointers(pa, pb);

	// The values are not swapped
	assert(a == firstValue);
	assert(b == secondValue);

	return 0;
}
