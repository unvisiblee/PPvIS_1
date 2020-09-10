#include "Matrix.h"
#include <iostream>
#include <ctime>

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

Matrix::~Matrix()
{
	for (int i = 0; i < lines; i++)
		delete[]matrix[i];

	delete[]matrix;
}

Matrix& Matrix::operator++()
{
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] += 1;

	return *this;
}

Matrix& Matrix::operator--()
{
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
	return nullptr;
}
