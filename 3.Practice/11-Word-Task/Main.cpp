#include <iostream>

#include "Word.h"
#include "Sentence.h"

int main()
{
	Word helloWorld("HelloWolrd");
	Word copy(helloWorld);

	helloWorld = helloWorld + '!';
	copy += '!';

	Sentence randomSentence("The best word in the world is ");

	std::cout << randomSentence << "\n";

	return 0;
}