/*!
	\file
	\brief Описание прототипов методов и полей класса Matrix
*/

#pragma once
#include <string>
using namespace std;

class Matrix {

private:
	int lines;
	int columns;
	int** elements;

public:
	Matrix();
	Matrix(int lines, int columns);
	Matrix(int lines, int columns, int from, int to);
	Matrix(const Matrix& other);
	~Matrix();
	void clean(Matrix& matrix);
	void newMemory();
	Matrix operator = (const Matrix& other);
	Matrix& operator ++ ();
	Matrix& operator ++ (int number);
	Matrix& operator -- ();
	Matrix& operator--(int number);
	bool operator==(Matrix& other);
	int* operator[](unsigned int index);
	int getLines();
	int getColumns();
	void setLinesNumber(unsigned int lines);  
	void setColumnsNumber(unsigned int columns);
	void fillSameElements(const Matrix& other);
	Matrix loadMatrixFromFile(const string& path);
	Matrix extractSubMatrix(unsigned int lines, unsigned int columns);
	string getMatrixType();
	Matrix transpose();
	friend bool isSquareType(const Matrix& matrix);
	friend bool isDiagonalType(const Matrix& matrix);
	friend bool isIdentityType(const Matrix& matrix);
	friend bool isNullType(const Matrix& matrix);
	friend bool isSymmetricType(const Matrix& matrix);
	friend bool isUpTriangleType(const Matrix& matrix);
	friend bool isDownTriangleType(const Matrix& matrix);
	friend ostream& operator << (ostream& os, const Matrix& matrix);
	friend istream& operator >> (istream& in, Matrix& matrix);
	friend void increment(Matrix& matrix);
	friend void decrement(Matrix& matrix);
	
};
