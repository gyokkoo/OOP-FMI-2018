#include <iostream>
#include <assert.h>
#include "DynamicArray.h"

const int COUNT = 16;

int main()
{
	// Testing the correctness of DynamicArray.cpp class
	DynamicArray dynamicArray;
	
	assert(dynamicArray.isEmpty());
	assert(dynamicArray.getCapacity() == INITIAL_CAPACITY);
	assert(dynamicArray.getSize() == 0);

	for (int i = 1; i <= COUNT; i++)
	{
		std::cout << "Added element: " << i << "\n";
		dynamicArray.pushBack(i);
		assert(dynamicArray.getAt(i - 1) == i);
	}

	assert(dynamicArray.getSize() == COUNT);

	dynamicArray.print();

	std::cout << "Insert at index [1] value 5: \n";
	dynamicArray.insertAt(1, 5);
	dynamicArray.print();

	std::cout << "Insert at last Index value 5: \n";
	dynamicArray.insertAt(dynamicArray.getSize() - 1, 5);
	dynamicArray.print();

	std::cout << "Removed first index:\n";
	dynamicArray.removeAt(0);
	dynamicArray.print();

	std::cout << "Removed last index:\n";
	dynamicArray.removeAt(dynamicArray.getSize() - 1);
	dynamicArray.print();

	std::cout << "PopBack last element:\n";
	dynamicArray.popBack();
	dynamicArray.print();

	std::cout << "Clear array:\n";
	dynamicArray.clear();
	dynamicArray.print();
	assert(dynamicArray.isEmpty());
	assert(dynamicArray.getCapacity() == INITIAL_CAPACITY);
	assert(dynamicArray.getSize() == 0);

	int capacity = 10;
	DynamicArray customArr(capacity);
	assert(customArr.isEmpty());
	assert(customArr.getCapacity() == capacity);
	assert(customArr.getSize() == 0);

	int newCapacity = 100;
	customArr.resize(newCapacity);
	assert(customArr.getCapacity() == newCapacity);

	newCapacity = 1;
	customArr.resize(newCapacity);
	assert(customArr.getCapacity() == newCapacity);

	customArr.pushBack(1);
	customArr.pushBack(11);
	customArr.pushBack(111);
	customArr.print();

	std::cout << "Copy array: \n";
	DynamicArray copyArray(customArr);
	copyArray.print();
	assert(!copyArray.isEmpty());

	return 0;
}