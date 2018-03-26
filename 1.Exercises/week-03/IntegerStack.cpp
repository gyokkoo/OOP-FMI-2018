#include <iostream>

const int MAX_LENGTH = 1024;

class MyIntegerStack
{
private:
	int arr[MAX_LENGTH];
	int lastIndex;
public:
	MyIntegerStack()
	{
		lastIndex = 0;
	}
	
	int getLength()
	{
		return lastIndex;
	}

	void push(int element)
	{
		arr[lastIndex] = element;
		lastIndex++;
	}

	int pop()
	{
		if (lastIndex == 0)
		{
			std::cout << "Stack is empty cannot pop elements\n";
			return -1;
		}

		int elementToRemove = arr[lastIndex - 1];
		lastIndex--;
		return elementToRemove;
	}

	int peek()
	{
		if (lastIndex == 0)
		{
			std::cout << "Cannot peek empty stack!\n";
			return -1;
		}

		return arr[lastIndex - 1];
	}
};

int main() 
{
	MyIntegerStack stack;
	for (int i = 1; i <= 20; i++)
	{
		stack.push(i);
		std::cout << "Added element " << i << "\n";
	}

	while (stack.getLength() > 0)
	{
		std::cout << "Removed element ";
		std::cout << stack.pop() << "\n";
	}

	return 0;
}