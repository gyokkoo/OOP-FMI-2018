#include <iostream>
#include <assert.h>
#include "List.h"

const int COUNT = 16;

int main()
{
	// Testing the correctness of List.cpp class
	List myList;
	
	assert(myList.isEmpty());
	assert(myList.getCapacity() == INITIAL_CAPACITY);
	assert(myList.getSize() == 0);

	for (int i = 1; i <= COUNT; i++)
	{
		std::cout << "Added element: " << i << "\n";
		myList.pushBack(i);
		assert(myList.getAt(i - 1) == i);
	}

	assert(myList.getSize() == COUNT);

	myList.print();

	std::cout << "Insert at index [1] value 5: \n";
	myList.insertAt(1, 5);
	myList.print();

	std::cout << "Insert at last Index value 5: \n";
	myList.insertAt(myList.getSize() - 1, 5);
	myList.print();

	std::cout << "Removed first index:\n";
	myList.removeAt(0);
	myList.print();

	std::cout << "Removed last index:\n";
	myList.removeAt(myList.getSize() - 1);
	myList.print();

	std::cout << "PopBack last element:\n";
	myList.popBack();
	myList.print();

	std::cout << "Clear array:\n";
	myList.clear();
	myList.print();
	assert(myList.isEmpty());
	assert(myList.getCapacity() == INITIAL_CAPACITY);
	assert(myList.getSize() == 0);

	int capacity = 10;
	List customList(capacity);
	assert(customList.isEmpty());
	assert(customList.getCapacity() == capacity);
	assert(customList.getSize() == 0);

	int newCapacity = 100;
	customList.resize(newCapacity);
	assert(customList.getCapacity() == newCapacity);

	newCapacity = 1;
	customList.resize(newCapacity);
	assert(customList.getCapacity() == newCapacity);

	customList.pushBack(1);
	customList.pushBack(11);
	customList.pushBack(111);
	customList.print();

	std::cout << "Copy list: \n";
	List copyList(customList);
	copyList.print();
	assert(!copyList.isEmpty());

	return 0;
}