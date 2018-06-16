#include <iostream>
#include "Book.h"

int main()
{
	Book geometriq("Sbornik Geometriq", 350);
	std::cout << geometriq;
	
	Book dis("Sbornik Analiz", 1300);
	std::cout << dis;

	if (geometriq < dis)
	{
		std::cout << geometriq;
	}
	else if (geometriq > dis)
	{
		std::cout << dis;
	}

	Book userInput;
	std::cin >> userInput;

	std::cout << userInput;

	return 0;
}