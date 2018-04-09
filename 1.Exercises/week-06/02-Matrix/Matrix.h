#pragma once
const int DEFAULT_SIZE = 3;

class Matrix
{
public:
	Matrix();
	Matrix(int size);
	Matrix(double** matrix, int size = DEFAULT_SIZE);
	Matrix(const Matrix& other);
	~Matrix();

	Matrix& operator=(const Matrix& matrix);
	Matrix operator+(const Matrix& matrix);
	Matrix operator-(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);
	Matrix operator*(double lambda);

	Matrix operator!();
	double operator*();

	int getSize() const;

	void setMatrix(double** matrix);

	// friend grants a function access to private members of the class where the friend declaration appears.
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
	friend std::istream& operator>>(std::istream& is, Matrix& matrix);
private:
	void deleteMatrix(double** matrixArr, int size);
	double determinantOfMatrix(double** matrix, int size);
	void getCofactor(double** matrix, double** temp, double p, double q, int n);
	void adjoint(double** matrix, double** adj);
	bool inverse(double** matrix, double** inverse);
private:
	int size;
	double** matrixArr;
};

