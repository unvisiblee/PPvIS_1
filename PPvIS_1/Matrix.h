/*!
	\file Описание прототипов методов и полей класса Matrix
*/

#pragma once
#include <string>
using namespace std;

class Matrix {

public:
	Matrix();
	Matrix(int lines, int columns);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix operator = (const Matrix& other);
	Matrix& operator ++ ();
	Matrix& operator ++ (int number);
	Matrix& operator -- ();
	Matrix& operator--(int a);
	bool operator==(Matrix& other);
	int* operator[](unsigned int index);
	void setLinesNumber(unsigned int);  
	void setColumnsNumber(unsigned int);
	Matrix loadMatrixFromFile(const string&);
	Matrix extractSubMatrix(unsigned int lines, unsigned int columns);
	string getMatrixType();
	Matrix transpose();
	int getLines();
	int getColumns();
	friend ostream& operator << (ostream& os, const Matrix& matrix);
	friend istream& operator >> (istream& in, Matrix& matrix);

private:
	int lines;
	int columns;
	int** elements;

};
