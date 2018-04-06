#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Matrix.h"

Matrix::Matrix() : matrixArr(nullptr), size(DEFAULT_SIZE)
{
}

Matrix::Matrix(int size) : matrixArr(nullptr)
{
	this->size = size;
}

Matrix::Matrix(double** matrix, int size)
{
	this->size = size;
	this->setMatrix(matrix);
}


Matrix::Matrix(const Matrix & other)
{
	this->size = other.size;
	if (other.matrixArr != nullptr)
	{
		this->setMatrix(other.matrixArr);
	}
	else 
	{
		this->matrixArr = nullptr;
	}
}

Matrix::~Matrix()
{
	deleteMatrix(this->matrixArr, this->size);
}

void Matrix::setMatrix(double ** matrix)
{
	this->deleteMatrix(this->matrixArr, this->size);
	this->matrixArr = new double*[this->size];
	for (int row = 0; row < this->size; row++)
	{
		this->matrixArr[row] = new double[this->size];
		for (int col = 0; col < this->size; col++)
		{
			this->matrixArr[row][col] = matrix[row][col];
		}
	}
}

Matrix Matrix::operator+(const Matrix& matrix)
{
	if (this->size != matrix.getSize())
	{
		std::cout << "Invalid Plus Operation! Cannot sum two matrices with different sizes!\n";
		assert(this->size == matrix.getSize());
	}

	double** matrixArr = new double*[this->size];
	for (int row = 0; row < this->size; row++)
	{
		matrixArr[row] = new double[this->size];
		for (int col = 0; col < this->size; col++)
		{
			matrixArr[row][col] = this->matrixArr[row][col] + matrix.matrixArr[row][col];
		}
	}

	Matrix resultMatrix(matrixArr, this->size);
	this->deleteMatrix(matrixArr, this->size);
	return resultMatrix;
}

Matrix Matrix::operator-(const Matrix& matrix)
{
	if (this->size != matrix.getSize())
	{
		std::cout << "Invalid Minus Operation! Cannot subtract two matrices with different sizes!\n";
		assert(this->size == matrix.getSize());
	}

	double** matrixArr = new double*[this->size];
	for (int row = 0; row < this->size; row++)
	{
		matrixArr[row] = new double[this->size];
		for (int col = 0; col < this->size; col++)
		{
			matrixArr[row][col] = this->matrixArr[row][col] - matrix.matrixArr[row][col];
		}
	}

	Matrix resultMatrix(matrixArr, this->size);
	deleteMatrix(matrixArr, this->size);
	return resultMatrix;
}

Matrix Matrix::operator*(const Matrix& matrix)
{
	double** arr = new double*[this->size];
	for (int row = 0; row < this->size; row++)
	{
		arr[row] = new double[this->size];
		for (int col = 0; col < this->size; col++)
		{
			double cellResult = 0;
			for (int i = 0; i < this->size; i++)
			{
				cellResult += this->matrixArr[row][i] * matrix.matrixArr[i][col];
			}
			arr[row][col] = cellResult;
		}
	}

	Matrix resultMatrix(arr, this->size);
	this->deleteMatrix(arr, this->size);
	return resultMatrix;
}

Matrix Matrix::operator!()
{
	Matrix result(this->size);
	double** inverseMatrix = new double*[this->size];
	for (int i = 0; i < this->size; i++)
	{
		inverseMatrix[i] = new double[this->size];
	}

	if (inverse(this->matrixArr, inverseMatrix))
	{
		result.setMatrix(inverseMatrix);
		this->deleteMatrix(inverseMatrix, this->size);
	}
	
	return result;
}

double Matrix::operator*()
{
	return determinantOfMatrix(this->matrixArr, this->size);
}

int Matrix::getSize() const
{
	return this->size;
}

void Matrix::deleteMatrix(double** matrixArr, int size)
{
	if (matrixArr == nullptr)
	{
		return;
	}

	for (int row = 0; row < size; row++)
	{
		delete[] matrixArr[row];
	}
	delete[] matrixArr;
}

void Matrix::getCofactor(double** matrix, double** temp, double p, double q, int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			//  Copying into temporary matrix only those element
			//  which are not in given row and column
			if (row != p && col != q)
			{
				temp[i][j++] = matrix[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

void Matrix::adjoint(double ** matrix, double ** adj)
{
	if (this->size == 1)
	{
		adj[0][0] = 1;
		return;
	}

	// temp is used to store cofactors of matrix[][]
	int sign = 1;
	double** temp = new double*[this->size];
	for (int row = 0; row < this->size; row++)
	{
		temp[row] = new double[this->size];
	}

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			// Get cofactor of A[i][j]
			getCofactor(matrix, temp, i, j, this->size);

			// sign of adj[j][i] positive if sum of row
			// and column indexes is even.
			sign = ((i + j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the
			// transpose of the cofactor matrix
			adj[j][i] = (sign)*(determinantOfMatrix(temp, this->size - 1));
		}
	}

	deleteMatrix(temp, this->size);
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool Matrix::inverse(double ** matrix, double ** inverse)
{
	// Find determinant of A[][]
	double det = determinantOfMatrix(matrix, this->size);
	if (det == 0)
	{
		std::cout << "Singular matrix, cannot find its inverse!\n";
		return false;
	}

	// Find adjoint
	double** adj = new double*[this->size];
	for (int row = 0; row < this->size; row++)
	{
		adj[row] = new double[this->size];
	}
	adjoint(matrix, adj);

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)"
	for (int i = 0; i< this->size; i++)
		for (int j = 0; j < this->size; j++)
			inverse[i][j] = adj[i][j] / double(det);

	deleteMatrix(adj, this->size);
	return true;
}

/* Recursive function for finding determinant of matrix.
n is current dimension of mat[][]. */
double Matrix::determinantOfMatrix(double** mat, int n)
{
	double D = 0; // Initialize result

			   //  Base case : if matrix contains single element
	if (n == 1)
		return mat[0][0];

	double** temp = new double*[this->size]; // To store cofactors
	for (int row = 0; row < this->size; row++)
	{
		temp[row] = new double[this->size];
	}

	int sign = 1;  // To store sign multiplier

				   // Iterate for each element of first row
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of mat[0][f]
		this->getCofactor(mat, temp, 0, f, n);
		D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);

		// terms are to be added with alternate sign
		sign = -sign;
	}

	this->deleteMatrix(temp, this->size);

	return D;
}

std::ostream & operator<<(std::ostream & os, const Matrix & matrix)
{
	if (matrix.matrixArr == nullptr)
	{
		return os;
	}
	
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			os << std::setw(5) << matrix.matrixArr[i][j];
		}
		os << "\n";
	}
	os << "\n";
	return os;
}

std::istream & operator>>(std::istream & is, Matrix & matrix)
{
	int size;
	std::cout << "Enter Matrix size:\n";
	is >> size;
	if (size < 0)
	{
		std::cout << "Invalid size! Enter again: \n";
		is >> size;
	}

	matrix.size = size;

	std::cout << "Enter matrix elements:\n";
	double** arr = new double*[size];
	int element;
	for (int i = 0; i < size; i++)
	{
		arr[i] = new double[size];
		for (int j = 0; j < size; j++)
		{
			is >> element;
			arr[i][j] = element;
		}
	}

	matrix.setMatrix(arr);
	matrix.deleteMatrix(arr, size);
	return is;
}
