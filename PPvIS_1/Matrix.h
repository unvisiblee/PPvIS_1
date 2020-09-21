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
	Matrix(const Matrix& other);
	~Matrix();
	Matrix operator = (const Matrix& other);
	Matrix& operator ++ ();
	Matrix& operator ++ (int number);
	Matrix& operator -- ();
	Matrix& operator--(int number);
	bool operator==(Matrix& other);
	int* operator[](unsigned int index);
	void setLinesNumber(unsigned int lines);  
	void setColumnsNumber(unsigned int columns);
	Matrix loadMatrixFromFile(const string& path);
	Matrix extractSubMatrix(unsigned int lines, unsigned int columns);
	string getMatrixType(const Matrix& matrix);
	Matrix transpose();
	int getLines();
	int getColumns();
	friend bool squareType(const Matrix& matrix);
	friend bool diagonalType(const Matrix& matrix, bool square);
	friend bool identityType(const Matrix& matrix, bool diagonal);
	friend bool nullType(const Matrix& matrix);
	friend bool symmetricType(const Matrix& matrix, bool square);
	friend bool upTriangleType(const Matrix& matrix, bool square);
	friend bool downTriangleType(const Matrix& matrix, bool square);
	friend ostream& operator << (ostream& os, const Matrix& matrix);
	friend istream& operator >> (istream& in, Matrix& matrix);

};
