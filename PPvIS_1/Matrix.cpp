/*!
\file
\brief Файл с описанием функционала класса Matrix
*/
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>

Matrix::Matrix()
{
	columns = 0;
	lines = 0;
	elements = nullptr;
}

Matrix::Matrix(int l, int c)
{
	/*!
		Конструктор принимает количество строк и столбцов матрицы и заполняет их случайными числами в диапазоне от -50 до 50
	*/
	lines = l;
	columns = c;

	elements = new int* [lines];
	for (int i = 0; i < lines; i++)
		elements[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] = rand() % 100 - 50;

	//cout << "Constructor " << this << endl;
}

Matrix::Matrix(const Matrix& other) 
{
	/*!
		Конструктор копирования создаёт новый объект и копирует в него другой, избегая проблем с памятью 
	*/
	columns = other.columns;
	lines = other.lines;

	elements = new int* [lines];
	for (int i = 0; i < lines; i++)
		elements[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] = other.elements[i][k];

	//cout << "Copy constructor " << this << endl;
}

Matrix::~Matrix()
{
	/*!
		Деструктор освобождает память, выделенную для матрицы
	*/
	if (lines > 0)
	{
		for (int i = 0; i < lines; i++)
		{
			delete[]elements[i];
		}
	}
	
	if (columns > 0)
	{
		delete[]elements;
	}

	//cout << "Destructor  " << this << endl;
}

int Matrix::getLines()
{
	/*!
		Геттер для получения количества строк данной матрицы
	*/
	return this->lines;
}

int Matrix::getColumns()
{
	/*!
		Геттер для получения столбцов данной матрицы
	*/
	return this->columns;
}

ostream& operator<<(ostream& os, const Matrix& p)
{
	/*!
		Перегрузка потокового оператора для вывода матрицы в консоль
	*/
	cout << "-----------\n";
	for (int i = 0; i < p.lines; i++)
	{
		for (int k = 0; k < p.columns; k++)
			os << p.elements[i][k] << "\t";

		os << endl << endl;
	}

	return os;
}

istream& operator>>(istream& in, Matrix& p)
{
	/*!
		Перегрузка потокового оператора для ввода матрицы вручную
	*/
	cout << "Fill in the matrix: \n";
	for (int i = 0; i < p.lines; i++) {
		for (int k = 0; k < p.columns; k++)
			in >> p.elements[i][k];
	}
	return in;
}

Matrix Matrix::operator=(const Matrix& other)
{
	/*!
		Перегрузка оператора присваивания передаёт элементы одной матрицы в соответсвующие индексы другой
	*/
	if (columns > 0)
	{
		for (int i = 0; i < lines; i++)
		{
			delete[] elements[i];
		}
	}

	if (lines > 0)
	{
		delete elements;
	}

	lines = other.lines;
	columns = other.columns;
	elements = new int* [lines];
	for (int i = 0; i < lines; i++)
		elements[i] = new int[columns];
	

	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			elements[i][j] = other.elements[i][j];

	/*delete this->elements;
	this->elements = newMatrix;*/

	return *this;
}

Matrix& Matrix::operator++()
{
	/*!
		Префиксный инкремент увеличивает каждый элемент матрицы на единицу
	*/
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] += 1;

	return *this;
}

Matrix& Matrix::operator++(int a)
{
	/*!
		Постфиксный инкремент увеличивает каждый элемент матрицы на единицу
	*/
	Matrix temp = *this;

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] += 1;

	return *this;
}

Matrix& Matrix::operator--()
{	/*!
		Префиксный декремент уменьшает каждый элемент матрицы на единицу
	*/
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] -= 1;

	return *this;
}

Matrix& Matrix::operator--(int a)
{
	/*!
		Префиксный декремент уменьшает каждый элемент матрицы на единицу
	*/
	Matrix temp = *this;

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] -= 1;

	return *this;
}

bool Matrix::operator==(Matrix& other)
{	/*!
		Перегрузка оператора сравнения возвращает true, если матрицы равны и false в ином случае
	*/
	if (this->lines != other.getLines() || this->columns != other.getColumns())
	{
		return false;
	}

	for (int i = 0; i < this->lines; i++)
	{
		for (int k = 0; k < this->columns; k++)
		{
			if (this->elements[i][k] != other.elements[i][k])
			{
				return false;
			}
		}
	}
	
	return true;
}

int* Matrix::operator[](unsigned int i)
{
	/*!
		Перегрузка оператора [] для доступа к элементу матрицы по индексу
	*/
	if (i > this->lines)
		throw "Index is out of bounds!";
	else return this->elements[i];
}

void Matrix::setLinesNumber(unsigned int newLinesNum)
{
	/*!
		Изменение количества строк матрицы
	*/
	int** newMatrix = new int* [newLinesNum];
	for (int i = 0; i < newLinesNum; i++)
		newMatrix[i] = new int[this->columns];

	for (int i = 0; i < newLinesNum; i++)
		for (int j = 0; j < this->columns; j++) {
			if (this->lines <= i)
				newMatrix[i][j] = 0;
			else
				newMatrix[i][j] = this->elements[i][j];
		}

	delete this->elements;
	this->elements = newMatrix;
	this->lines = newLinesNum;
}

void Matrix::setColumnsNumber(unsigned int newColumnsNum)
{
	/*!
		Изменение количества столбцов матрицы
	*/
	int** newMatrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
		newMatrix[i] = new int[newColumnsNum];

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < newColumnsNum; j++) {
			if (this->columns <= j)
				newMatrix[i][j] = 0;
			else
				newMatrix[i][j] = this->elements[i][j];
		}

	delete this->elements;
	this->elements = newMatrix;
	this->columns = newColumnsNum;
}

Matrix Matrix::loadMatrixFromFile(const string& filepath)
{
	/*!
		Принимает путь к файлу с матрицей и возвращает объект с данной матрицей
	*/
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

Matrix Matrix::extractSubMatrix(unsigned int lines, unsigned int columns)
{
	/*!
		Возвращает подматрицу заданных размеров
	*/
	if (lines > this->lines || columns > this->columns)
		throw "Index out of bounds!";

	Matrix newMatrix(lines, columns);

	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			newMatrix[i][j] = elements[i][j];

	return newMatrix;
}

Matrix Matrix::transpose()
{
	/*!
		Возвращает матрицу транспонированную данной
	*/
	Matrix newMatrix(this->columns, this->lines);

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			newMatrix[j][i] = this->elements[i][j];

	return newMatrix;
}

string Matrix::getMatrixType()
{
	/*!
		Метод возвращает строку, которая описывает тип матрицы (квадратная, диагональная, нулевая, единичная, симметрическая,
верхняя треугольная, нижняя треугольная)
	*/
	string result = "";
	bool square = false;
	if (this->columns == this->lines)
	{
		square = true;
	}

	bool diagonal;
	if (!square)
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

				if (this->elements[i][k] == 0)
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

	bool identity = false;
	if (diagonal)
	{
		int ones = 0;
		int k = 0;
		for (int i = 0; i < this->lines; i++)
		{
			if (this->elements[i][k] == 1)
			{
				ones++;
			}
			k++;
		}

		if (ones == this->columns)
		{
			identity = true;
		}
	}

	bool nullM = true;
	for (int i = 0; i < this->lines; i++)
	{
		for (int k = 0; k < this->columns; k++)
		{
			if (this->elements[i][k] != 0)
			{
				nullM = false;
			}
		}
	}

	bool symmetricM = true;
	if (square)
	{
		for (int i = 0; i < this->lines; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				if (i == j)
				{
					continue;
				}

				if (this->elements[j][i] != this->elements[i][j])
				{
					symmetricM = false;
				}
			}
		}
	}

	bool upTriangle = true;
	if (square)
	{
		for (int i = 0; i < this->lines; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				if (i > j && this->elements[i][j] != 0)
				{
					upTriangle = false;
				}
			}
		}
	}

	bool downTriangle = true;
	if (square)
	{
		for (int i = 0; i < this->lines; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				if (i < j && this->elements[i][j] != 0)
				{
					downTriangle = false;
				}
			}
		}
	}

	if (downTriangle && !nullM)
	{
		result += "Down Triangle ";
	}
	else if (upTriangle && !nullM)
	{
		result += "UpperTriangle ";
	}

	if (symmetricM && !diagonal)
	{
		result += "Symmetric ";
	}

	if (identity)
	{
		result += "Identity ";
	}

	if (nullM)
	{
		result = "Null ";
	}

	if (diagonal && !nullM && !identity)
	{
		result += "Diagonal ";
	}

	if (square && !diagonal && !identity && !symmetricM && !downTriangle && !upTriangle)
	{
		result += "Square ";
	}

	return "Matrix type is " + result + "\n";
}
