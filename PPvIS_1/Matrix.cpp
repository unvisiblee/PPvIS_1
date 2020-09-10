#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;

	this->matrix = new int* [lines];
	for (int i = 0; i < lines; i++)
		matrix[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] = rand() % 30 - 15;

}

Matrix::Matrix(const Matrix& other) // shit copy constructor (to remake)
{
	this->matrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
		matrix[i] = new int[this->columns];

	for (int i = 0; i < this->lines; i++)
		for (int k = 0; k < this->columns; k++)
			this->matrix[i][k] = other.matrix[i][k];

}

Matrix::~Matrix() //clean memory destructor
{
	for (int i = 0; i < lines; i++)
		delete[]matrix[i];

	delete[]matrix;
}

Matrix& Matrix::operator++() // prefix
{
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] += 1;

	return *this;
}

Matrix& Matrix::operator++(int a) // postfix
{
	Matrix temp(*this);

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] += 1;

	return *this;
}

Matrix& Matrix::operator--() // prefix
{
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] -= 1;

	return *this;
}

Matrix& Matrix::operator--(int a) // postfix
{
	Matrix temp(*this);

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] -= 1;

	return *this;
}

void Matrix::Print()
{
	for (int i = 0; i < lines; i++)
	{
		for (int k = 0; k < columns; k++)
			cout << matrix[i][k] << "\t";

		cout << endl << endl;
	}
		
}

void Matrix::setRowsNum(unsigned int)
{
}

void Matrix::setColumnsNum(unsigned int)
{
}

Matrix* Matrix::loadMatrixFromFile(const string&)
{
	return nullptr;
}

Matrix* Matrix::extractSubMatrix(unsigned int, unsigned int)
{
	return nullptr;
}

string Matrix::getMatrixType()
{
	return string();
}

Matrix* Matrix::transpose()
{
	int temp;


	return this;
}
