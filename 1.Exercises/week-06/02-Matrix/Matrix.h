#pragma once

const int DEFAULT_SIZE = 3;

class Matrix
{
public:
	Matrix();
	Matrix(int** matrix, int size = DEFAULT_SIZE);
	Matrix(const Matrix& other);
	~Matrix();

	Matrix operator+(const Matrix& matrix);
	Matrix operator-(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);
	// Matrix operator*(const Vector& vector);
	double** operator!();
	int operator*();

	int getSize() const;

	void setMatrix(int** matrix);

	// friend grants a function access to private members of the class where the friend declaration appears.
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
	friend std::istream& operator>>(std::istream& is, Matrix& matrix);

private:
	void deleteMatrix(int** matrixArr, int size);
	int determinantOfMatrix(int** matrix, int size);
	void getCofactor(int** matrix, int** temp, int p, int q, int n);
	void adjoint(int** matrix, int** adj);
	bool inverse(int** matrix, double** inverse);
private:
	int size;
	int** matrixArr;
};