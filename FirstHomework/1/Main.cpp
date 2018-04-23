#include <iostream>
#include <cmath>
#include "Stack.h"

// Input string max size
const int MAX_SIZE = 101;

// Helper function to find the length of given string
int myStrelen(const char* str);

// Check if given symbol is number or not
bool isNumber(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

double getFirstNumber(char* str, int& index)
{
	double number = 0;
	bool isNegative = false;
	char numberBuilder[MAX_SIZE];
	int builderIndex = 0;

	char currentSymbol = str[index];
	if (currentSymbol == '-')
	{
		isNegative = true;
		index++;
	}

	while (currentSymbol != ' ')
	{
		numberBuilder[builderIndex] = currentSymbol;
		index++;
		builderIndex++;
		currentSymbol = str[index];
	}

	numberBuilder[builderIndex] = '\0';

	// Convert a string to double number
	number = atof(numberBuilder);
	if (isNegative)
	{
		number *= -1;
	}

	return number;
}

double calculate(char* str)
{
	if (str == nullptr || myStrelen(str) >= MAX_SIZE)
	{
		std::cout << "Invalid string!\n";
		return 0;
	}

	Stack stack;
	double firstNumber = 0;
	double secondNumber = 0;
	int length = myStrelen(str);
	for (int i = 0; i < length; i++)
	{
		char currentChar = str[i];
		if (isNumber(currentChar) || 
			(currentChar == '-' && i + 1 < length && isNumber(str[i + 1])))
		{
			double number = getFirstNumber(str, i);
		    stack.push(number);
		}
		else if (currentChar == ' ')
		{
			continue;
		}
		else
		{
			secondNumber = stack.pop();
			firstNumber = stack.pop();
			switch (currentChar)
			{
			case '+':
				stack.push(firstNumber + secondNumber);
				break;
			case '-':
				stack.push(firstNumber - secondNumber);
				break;
			case '*':
				stack.push(firstNumber * secondNumber);
				break;
			case '/':
				if (secondNumber != 0)
				{
					stack.push(firstNumber / secondNumber);
				}
				else
				{
					std::cout << "Error! Cannot / by zero!\n";
					return 0;
				}
				break;
			case '%':
				if (floor(firstNumber) == firstNumber &&
					floor(secondNumber) == secondNumber)
				{
					int first = (int)firstNumber;
					int second = (int)secondNumber;
					stack.push(first % second);
				}
				else
				{
					std::cout << "Error! Cannot use % on floating point number\n";
					return 0;
				}
				break;
			default:
				std::cout << "Invalid operation!\n";
				return 0;
			}
		}
	}

	return stack.peek();
}

int main()
{
	char firstInput[MAX_SIZE] = "3 11 5 + -";
	std::cout << firstInput << " = " << calculate(firstInput) << "\n";
	
	char secondInput[MAX_SIZE] = "2.5 3.254 11.12 + 5.34 - *";
	std::cout << secondInput << " = " << calculate(secondInput) << "\n";

	char thirdInput[MAX_SIZE] = "5 1 2 + 4 * + 3 -";
	std::cout << thirdInput << " = " << calculate(thirdInput) << "\n";

	char fourthInput[MAX_SIZE] = "15 7 1 1 + - / 3 * 2 1 1 + + -";
	std::cout << fourthInput << " = " << calculate(fourthInput) << "\n";

	char input[MAX_SIZE];

	std::cout << "Enter a valid reverse polish notation:\n";
	std::cin.getline(input, MAX_SIZE - 1);

	double result = calculate(input);
	std::cout << input << " = " << result << "\n";
	
	return 0;
}

int myStrelen(const char * str)
{
	int index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return index;
}
