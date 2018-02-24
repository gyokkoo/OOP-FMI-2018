/**
*
* Solution to exercises
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 6
* @compiler VC
*
*/

#include <iostream>

void printReversed(int* arr, int index)
{
	if (index < 0)
	{
		return;
	}

	std::cout << arr[index] << " ";
	printReversed(arr, index - 1);
}

int main()
{
	int n = 0;
	std::cout << "n = ";
	std::cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	printReversed(arr, n - 1);
	std::cout << "\n";

	std::cout << "Cleaning up memory...\n";
	delete[] arr;
	std::cout << "Done! \n";

	system("pause");
	return 0;
}