/**
*
* Solution to exercises
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 4
* @compiler VC
*
*/

#include <iostream>

size_t myStrLen(const char* str)
{
	size_t index = 0;
	while (str[index])
	{
		index++;
	}

	return index;
}

bool doExist(const char* str, const char* subStr)
{
	size_t strLength = myStrLen(str);
	size_t subStrLength = myStrLen(subStr);
	bool doSubStrExists;
	int index = 0;

	for (int i = 0; i <= strLength - subStrLength; i++)
	{
		doSubStrExists = true;
		for (int j = 0; j < subStrLength; j++)
		{
			if (subStr[j] != str[i])
			{
				doSubStrExists = false;
				break;
			}
			else
			{
				i++;
			}
		}

		// if this is true it means that the text contains the word!
		if (doSubStrExists)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	char text[100] = "Hello OOP world!";
	char word[100] = "OOP";
	
	std::cout << doExist(text, word) << "\n";
	std::cout << doExist("A", "B") << "\n";
	std::cout << doExist("Hello", "eo") << "\n";
	std::cout << doExist("Hello", "Hello") << "\n";

	system("pause");
	return 0;
}