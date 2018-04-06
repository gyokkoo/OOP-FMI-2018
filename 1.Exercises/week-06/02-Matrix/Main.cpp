#include <iostream>
#include "Matrix.h"

double** createMatrix(int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}

	return matrix;
}

void deleteMatrix(double** arr, int n)
{
	std::cout << "Cleaning up memory... ";
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	std::cout << "Done!\n";
}

int main()
{
	/*
	Matrix m;
	std::cin >> m;
	std::cout << m;
	*/

	// int size = 6;
	int size = 3;
	int counter = 1;
	double** matrixA = createMatrix(size);
	double** matrixB = createMatrix(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrixA[i][j] = counter++;
			matrixB[i][j] = counter * 2;
		}
	}

	Matrix a(matrixA, size);
	Matrix b(matrixB, size);

	std::cout << "Matrix a:\n" << a;
	std::cout << "Matrix b:\n" << b;

	Matrix aPlusB = a + b;
	std::cout << "a + b = \n" << aPlusB;

	Matrix bMinusA = b - a;
	std::cout << "b - a = \n" << bMinusA;

	Matrix aMultiplyB = a * b;
	std::cout << "a * b = \n" << aMultiplyB;

	int simpleMatrixSize = 2;
	double** simpleMatrix = createMatrix(simpleMatrixSize);
	simpleMatrix[0][0] = 4;
	simpleMatrix[0][1] = 3;
	simpleMatrix[1][0] = 3;
	simpleMatrix[1][1] = 2;

	Matrix matrixC(simpleMatrix, simpleMatrixSize);
	std::cout << "Matrix C = \n" << matrixC;
	
	double determinant = *matrixC;
	std::cout << "Determinant of matrix C = " << determinant << "\n";
	
	Matrix inverse = !matrixC;
	std::cout << "Inverse matrix of matrix C:\n" << inverse;
	
	deleteMatrix(matrixA, size);
	deleteMatrix(matrixB, size);
	deleteMatrix(simpleMatrix, simpleMatrixSize);
	
	return 0;
}