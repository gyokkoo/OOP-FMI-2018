#include <iostream>
#include <assert.h>
#include "Stack.h"

const int COUNT = 10;

int main() 
{
	Stack myStack;
	
	for (int i = 1; i <= COUNT; i++)
	{
		myStack.push(i);
		assert(i == myStack.peek());
		std::cout << "Added element: " << i << "\n";
	}

	Stack copyStack(myStack);

	// Aborts the program if the conditions are false
	assert(COUNT == myStack.peek());
	assert(COUNT == myStack.getLength());
	assert(COUNT == copyStack.peek());
	assert(COUNT == copyStack.getLength());

	while (myStack.getLength() > 0)
	{
		std::cout << "Removed element: " << myStack.pop() << "\n";
	}

	assert(0 == myStack.getLength());
	assert(COUNT == copyStack.getLength());

	return 0;
}