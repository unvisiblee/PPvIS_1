#pragma once
#include <string>
using namespace std;

class Matrix {
public:
	Matrix(int lines, int columns);
	Matrix(const Matrix& other);
	~Matrix();
	void operator = (const Matrix& other);
	Matrix& operator ++ ();
	Matrix& operator ++ (int a);
	Matrix& operator -- ();
	Matrix& operator--(int a);
	bool operator==(Matrix& other);
	int* operator[](unsigned int i);
	void print();
	void setLinesNum(unsigned int);  
	void setColumnsNum(unsigned int);
	Matrix loadMatrixFromFile(const string&);
	Matrix extractSubMatrix(unsigned int,unsigned int);
	string getMatrixType();
	void transpose();
	int getLines();
	int getColumns();

private:
	int lines;
	int columns;
	int** matrix;

};
