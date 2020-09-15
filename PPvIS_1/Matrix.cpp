#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int l, int c)
{
	lines = l;
	columns = c;

	matrix = new int* [lines];
	for (int i = 0; i < lines; i++)
		matrix[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] = rand() % 2;

}

Matrix::Matrix(const Matrix& other) // copy constructor
{
	this->columns = other.columns;
	this->lines = other.lines;

	this->matrix = new int* [lines];
	for (int i = 0; i < lines; i++)
		matrix[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
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
	Matrix temp = *this;

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
	Matrix temp = *this;

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] -= 1;

	return *this;
}


int* Matrix::operator[](unsigned int i) {
	if (i > this->lines)
		throw "Index is out of bounds!";
	else return this->matrix[i];
}

void Matrix::print()
{
	cout << "-----------\n";
	for (int i = 0; i < lines; i++)
	{
		for (int k = 0; k < columns; k++)
			cout << matrix[i][k] << "\t";

		cout << endl << endl;
	}
		
}

void Matrix::setLinesNum(unsigned int newLinesNum) {
	int** newMatrix = new int* [newLinesNum];
	for (int i = 0; i < newLinesNum; i++)
		newMatrix[i] = new int[this->columns];

	for (int i = 0; i < newLinesNum; i++)
		for (int j = 0; j < this->columns; j++) {
			if (this->lines <= i)
				newMatrix[i][j] = 0;
			else
				newMatrix[i][j] = this->matrix[i][j];
		}

	delete this->matrix;
	this->matrix = newMatrix;
	this->lines = newLinesNum;
}

void Matrix::setColumnsNum(unsigned int newColumnsNum) {
	int** newMatrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
		newMatrix[i] = new int[newColumnsNum];

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < newColumnsNum; j++) {
			if (this->columns <= j)
				newMatrix[i][j] = 0;
			else
				newMatrix[i][j] = this->matrix[i][j];
		}

	delete this->matrix;
	this->matrix = newMatrix;
	this->columns = newColumnsNum;
}

int Matrix::getLines()
{
	return this->lines;
}

int Matrix::getColumns()
{
	return this->columns;
}

Matrix* Matrix::loadMatrixFromFile(const string& filepath)
{
	return nullptr;
}

Matrix Matrix::extractSubMatrix(unsigned int lines, unsigned int columns) {
	if (lines > this->lines || columns > this->columns)
		throw "Index out of bounds!";

	Matrix newMatrix(lines, columns);

	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			newMatrix[i][j] = matrix[i][j];

	return newMatrix;
}

string Matrix::getMatrixType()
{
	string result = "";

	if (this->columns == this->lines)
	{
		result += "Square ";
	}

	bool diagonal;

	if (result != "Square ")
	{
		diagonal = false;
	}
	else
	{
		int zeros = 0;
		for (int i = 0; i < this->lines; i++)
		{
			for (int k = 0; k < this->columns; k++)
			{
				if (i == k)
				{
					continue;
				}

				if (this->matrix[i][k] == 0)
				{
					zeros++;
				}
			}
		}

		if (zeros == (this->lines * this->columns - this->columns))
		{
			diagonal = true;
		}
	}

	if (diagonal)
	{
		result = "Diagonal ";
	}

	

	return "Matrix type is " + result + "\n";
}

void Matrix::transpose() {
	int** newMatrix = new int* [this->columns];
	for (int i = 0; i < this->columns; i++)
		newMatrix[i] = new int[this->lines];

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++) {
			newMatrix[j][i] = this->matrix[i][j];
		}
	
	delete this->matrix;
	this->matrix = newMatrix;
	swap(this->columns, this->lines);
}


