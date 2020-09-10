#pragma once
#include <string>
using namespace std;

class Matrix {
public:
	Matrix(int lines, int columns);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator ++ ();
	Matrix& operator ++ (int a);
	Matrix& operator -- ();
	Matrix& operator--(int a);
	void Print();
	void setRowsNum(unsigned int);  
	void setColumnsNum(unsigned int);
	Matrix* loadMatrixFromFile(const string&);
	Matrix* extractSubMatrix(unsigned int,unsigned int);
	string getMatrixType();
	Matrix* transpose();

private:
	// all other methods here
	int lines;
	int columns;
	int** matrix;
};
