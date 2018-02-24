/**
*
* Solution to exercises
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 5
* @compiler VC
*
*/

#include <iostream>

int* getArr(int L)
{
	int* arr = new int[L];
	for (int i = 0; i < L; i++)
	{
		arr[i] = i + 1;
	}

	return arr;
}

int main()
{
	int L = 0;
	std::cin >> L;

	int* arr = getArr(L);
	for (int i = 0; i < L; i++)
	{
		std::cout << arr[i] << "\n";
	}

	std::cout << "Cleaning up memory...\n";
	delete[] arr;
	std::cout << "Done! \n";
	
	system("pause");
	return 0;
}