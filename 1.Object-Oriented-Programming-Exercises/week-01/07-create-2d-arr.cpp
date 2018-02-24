/**
*
* Solution to exercises
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 7
* @compiler VC
*
*/

#include <iostream>

int** getArr(int n, int m)
{
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = i + j;
		}
	}

	return arr;
}

int main()
{
	int n = 0, m = 0;
	std::cout << "Enter n and m:\n";
	std::cin >> n;
	std::cin >> m;

	int** arr = getArr(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << "\n";
	}

	std::cout << "Cleaning up memory...\n";
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	std::cout << "Done!\n";

	system("pause");
	return 0;
}