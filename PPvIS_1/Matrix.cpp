#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>

Matrix::Matrix(int l, int c)
{
	lines = l;
	columns = c;

	matrix = new int* [lines];
	for (int i = 0; i < lines; i++)
		matrix[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			matrix[i][k] = rand() % 30 - 16;

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

void Matrix::operator=(const Matrix& other)
{
	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			this->matrix[i][j] = other.matrix[i][j];

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

bool Matrix::operator==(Matrix& other)
{
	if (this->lines != other.getLines() || this->columns != other.getColumns())
	{
		return false;
	}

	for (int i = 0; i < this->lines; i++)
	{
		for (int k = 0; k < this->columns; k++)
		{
			if (this->matrix[i][k] != other.matrix[i][k])
			{
				return false;
			}
		}
	}
	
	return true;
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

Matrix Matrix::loadMatrixFromFile(const string& filepath) {
	ifstream fin;
	fin.open(filepath);
	if (!fin.is_open())
		throw "Error while opening file!";

	unsigned int lines, columns;
	int elem;	
	string buff;
	stringstream ss;
	getline(fin, buff);
	ss << buff;
	ss >> lines;
	ss >> columns;
	Matrix newMatrix(lines, columns);
	for (int i = 0; i < lines; i++) {
		getline(fin, buff);
		stringstream ss;
		ss << buff;
		for (int j = 0; j < columns; j++) {
			ss >> elem;
			newMatrix[i][j] = elem;
		}
	}

	return newMatrix;
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

void Matrix::transpose() {
	int** newMatrix = new int* [this->columns];
	for (int i = 0; i < this->columns; i++)
		newMatrix[i] = new int[this->lines];

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			newMatrix[j][i] = this->matrix[i][j];

	delete this->matrix;
	this->matrix = newMatrix;
	swap(this->columns, this->lines);

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
		else
		{
			diagonal = false;
		}
	}

	if (diagonal)
	{
		result = "Diagonal ";
	}

	if (diagonal)
	{
		int ones = 0;
		int k = 0;
		for (int i = 0; i < this->lines; i++)
		{
			if (this->matrix[i][k] == 1)
			{
				ones++;
			}
			k++;
		}

		if (ones == this->columns)
		{
			result += "Identity ";
		}
	}

	int zeros = 0;
	for (int i = 0; i < this->lines; i++)
	{
		for (int k = 0; k < this->columns; k++)
		{
			if (this->matrix[i][k] == 0)
			{
				zeros++;
			}
		}
	}

	if (zeros == (this->columns * this->lines))
	{
		result += "Null ";
	}

	/*Matrix trans = this->transpose();
	if (this->operator==(trans))
	{
		result += "Symmetric ";
	}*/

	if (this->columns == this->lines)
	{
		int symmetric = 0;
		for (int i = 0; i < this->lines; i++)
		{ 
			for (int j = 0; j < this->columns; j++)
			{
				if (i == j)
				{
					continue;
				}

				if (this->matrix[j][i] = this->matrix[i][j])
				{
					symmetric++;
				}
			}
		}
		if (symmetric == this->columns * this->columns - this->columns)
		{
			result += "Symmetric ";
		}
	}

	if (this->columns == this->lines)
	{
		bool upTriangle = false;
		for (int i = 0; i < this->lines; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				if (i + j < this->columns + this->lines - 2 && this->matrix[i][j] != 0)
				{
					upTriangle = false;
				}
			}
		}
		if (upTriangle)
		{
			result += "Upper Triangle ";
		}
	}

	if (this->columns == this->lines)
	{
		bool downTriangle = false;
		for (int i = 0; i < this->lines; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				if (i + j > this->columns + this->lines - 2 && this->matrix[i][j] != 0)
				{
					downTriangle = false;
				}
			}
		}
		if (downTriangle)
		{
			result += "Down Triangle ";
		}
	}

	return "Matrix type is " + result + "\n";
}
