/**
*
* Solution to exercises
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <assert.h>

using std::cout;

int myStrlen(const char* str)
{
	const char* pRead = str;
	while (*pRead != '\0')
	{
		pRead++;
	}

	return pRead - str;
}

void myStrcopy(char* destination, const char* source)
{
	do 
	{
		// The null terminator will be copied
		*destination = *source;
		destination++;
	} while (*source++ != '\0');
}

void myStrcat(char* destination, const char* source)
{
	char *p = destination;
	while (*p != '\0')
	{
		p++;
	}

	myStrcopy(p, source);
}

int myStrcmp(const char* str1, const char* str2)
{
	unsigned char c1, c2;
	int difference;
	do 
	{
		c1 = (unsigned char)*str1++;
		c2 = (unsigned char)*str2++;

		difference = c1 - c2;
	} while ((difference == 0) && (c1 != '\0'));

	return difference;
}

int main()
{
	// Do not change the values
	char textA[100] = { 'a', 'b', 'c', '\0' };
	char textB[100] = { 'a', 'b', 'd', 'f' ,'\0' };

	cout << "The length of " << textA << " is " << myStrlen(textA) << "\n";
	cout << "The length of " << textB << " is " << myStrlen(textB) << "\n";
	assert(myStrlen(textA) == 3);
	assert(myStrlen(textB) == 4);

	cout << "TextA: " << textA << "\n";
	cout << "TextB: " << textB << "\n";
	myStrcat(textA, textB);
	cout << "After strcat(textA, textB): " << textA << "\n";
	assert(myStrlen(textA) == 3 + 4);
	assert(myStrcmp((textA), "abcabdf") == 0);

	cout << "TextA: " << textA << "\n";
	cout << "TextB: " << textB << "\n";
	myStrcopy(textA, textB);
    cout << "After strcopy(textA, textB): " << textA << "\n";
	assert(myStrlen(textA) == 4);
	assert(myStrcmp(textA, textB) == 0);


	cout << "strcmp(\"abc\", \"abb\"): " << myStrcmp("abc", "abb") << "\n";
	cout << "strcmp(\"a\", \"ab\"): " << myStrcmp("a", "ab") << "\n";
	cout << "strcmp(\"ab\", \"ab\"): " << myStrcmp("ab", "ab") << "\n";

	assert(myStrcmp("abc", "abb") > 0);
	assert(myStrcmp("a", "ab") < 0);
	assert(myStrcmp("ab", "ab") == 0);
	
	system("pause");
	return 0;
}
