/*!
\file
\brief Файл с описанием функционала класса Matrix
*/
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>

Matrix::Matrix()
{/*!
	\brief Конструктор по умолчанию, который устанавливает начальное положение объекта. Не принимает параметров
 */
	columns = 0;
	lines = 0;
	elements = nullptr;
}

Matrix::Matrix(int lines_p, int columns_p)
{
	/*!
		Конструктор принимает количество строк и столбцов матрицы и заполняет их случайными числами в диапазоне от -50 до 50
		\param lines_p количество строк в содаваемой матрице
		\param columns_p количество столбцов в создаваемой матрице
	*/
	lines = lines_p;
	columns = columns_p;

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
		\param other ссылка на второй объект копирования
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
		Деструктор освобождает память, выделенную для матрицы. Не принимает параметров
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

}

int Matrix::getLines()
{
	/*!
		Геттер для получения количества строк данной матрицы. Не принимает параметров
		\return Количество строк данной матрицы
	*/
	return this->lines;
}

int Matrix::getColumns()
{
	/*!
		Геттер для получения столбцов данной матрицы. Не принимает параметров
		\return Количество столбцов данной матрицы
	*/
	return this->columns;
}

ostream& operator<<(ostream& os, const Matrix& matrix)
{
	/*!
		Перегрузка потокового оператора для вывода матрицы в консоль
		\return объект типа ostream, который выводится на экран
		\param os ссылка на объект типа ostream, который выводится на экран
		\param matrix матрица, которая выводится на экран
	*/
	cout << "-----------\n";
	for (int i = 0; i < matrix.lines; i++)
	{
		for (int k = 0; k < matrix.columns; k++)
			os << matrix.elements[i][k] << "\t";

		os << endl << endl;
	}

	return os;
}

istream& operator>>(istream& in, Matrix& matrix)
{
	/*!
		Перегрузка потокового оператора для ввода матрицы вручную
		\param in объект типа istream, который принимает в себя значения, считываемые из клавиатуры при вводе в консоли
		\param matrix матрица, элементы которой вводятся
		\return объект типа istream, который заполняет матрицу вводёнными числами
	*/
	cout << "Fill in the matrix: \n";
	for (int i = 0; i < matrix.lines; i++) {
		for (int k = 0; k < matrix.columns; k++)
			in >> matrix.elements[i][k];
	}
	return in;
}

Matrix Matrix::operator=(const Matrix& other)
{
	/*!
		Перегрузка оператора присваивания передаёт элементы одной матрицы в соответсвующие индексы другой
		\param other второй объект типа матрица в операции присваивания
		\return разыменованный указатель на данную матрицу
		\details в ходе выполнения функции выполняется освобождение памяти старого объекта и выделяется новая память. Элементы поиндексно переносятся из other в this
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
		\return Разыменованный указатель на данную матрицу
	*/
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] += 1;

	return *this;
}

Matrix& Matrix::operator++(int number)
{
	/*!
		Постфиксный инкремент увеличивает каждый элемент матрицы на единицу
		\return Разыменованный указатель на данную матрицу
		\param number нужен для отличия от префиксного инкремента, согласно документации с++
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
		\return Разыменованный указатель на данную матрицу
	*/
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] -= 1;

	return *this;
}

Matrix& Matrix::operator--(int number)
{
	/*!
		Префиксный декремент уменьшает каждый элемент матрицы на единицу
		\return Разыменованный указатель на данную матрицу
		\param number нужен для отличия от префиксного декремента, согласно документации с++
	*/
	Matrix temp = *this;

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] -= 1;

	return *this;
}

bool Matrix::operator==(Matrix& other)
{	/*!
		Перегрузка оператора сравнения осуществляется поэлементный сравнением матриц (соответствующих индексов)
		\param other ссылка на вторую матрицу в сравнении на равенство
		\return возвращает true, если матрицы равны и false в ином случае
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

int* Matrix::operator[](unsigned int index)
{
	/*!
		Перегрузка оператора [] для доступа к элементу матрицы по индексу
		\return Массив значений строки матрицы заданного индекса
		\param index индекс строки матрицы
		\details впоследствии можно применить еще один оператор [] для получения конкретного элемента, а не целой строки
	*/
	if (index > this->lines || index < 0)
		throw "Index is out of bounds!";
	else return this->elements[index];
}

void Matrix::setLinesNumber(unsigned int newLinesNumber)
{
	/*!
		Изменение количества строк матрицы
		\param newLinesNumber число строк в новой матрице
		\details в ходе выполнения метода создаётся новая матрица, элементы с одинаковым индексом от предыдущей матрицы остаются теми же. В дополнительные ячейки, если введено число строк, превосходящее число строк изначальной матрицы, помещяются нули
	*/
	int** newMatrix = new int* [newLinesNumber];
	for (int i = 0; i < newLinesNumber; i++)
		newMatrix[i] = new int[this->columns];

	for (int i = 0; i < newLinesNumber; i++)
		for (int j = 0; j < this->columns; j++) {
			if (this->lines <= i)
				newMatrix[i][j] = 0;
			else
				newMatrix[i][j] = this->elements[i][j];
		}

	delete this->elements;
	this->elements = newMatrix;
	this->lines = newLinesNumber;
}

void Matrix::setColumnsNumber(unsigned int newColumnsNumber)
{
	/*!
		Изменение количества столбцов матрицы
		\param newColumnsNumber число столбцов в новой матрице
		\details в ходе выполнения метода создаётся новая матрица, элементы с одинаковым индексом от предыдущей матрицы остаются теми же. В дополнительные ячейки, если введено число столбцов, превосходящее число столбцов изначальной матрицы, помещяются нули
	*/
	int** newMatrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
		newMatrix[i] = new int[newColumnsNumber];

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < newColumnsNumber; j++) {
			if (this->columns <= j)
				newMatrix[i][j] = 0;
			else
				newMatrix[i][j] = this->elements[i][j];
		}

	delete this->elements;
	this->elements = newMatrix;
	this->columns = newColumnsNumber;
}

Matrix Matrix::loadMatrixFromFile(const string& filepath)
{
	/*!
		\briefЗагрузка матрицы из файла
		\details файл представляет собой набор чисел, первые два которые означают число строк и столбцов матрицы, а последующие элементы матрицы, записанные через пробел и переносы строк, соответсвенно строкам и столбцам получаемой матрицы
		\param filepath константная строка передаётся по ссылке, содержащая путь (имя) файла, из которого считывается матрица
		\return объект матрицы, считанной из файла
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
		\details Новая матрицы получается путём "обрезания" данной. Элементы и индексы сохраняются, если они соответсвуют новым заданным размерам
		\brief Извлекает подматрицу заданных размеров
		\param lines число строк новой матрицы
		\param columns число столбцов новой матрицы
		\return объект матрицы, которая является подматрицей исходной матрицы
	*/
	if (lines > this->lines || columns > this->columns || lines <= 0 || columns <= 0)
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
		\brief выполняется операция транспонирования
		\details элемент индекса [i][j] становится элементом [j][i], что соответсвует "переворачиванию" матрицы
		\code
		for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			newMatrix[j][i] = this->elements[i][j];
		\endcode
		\return объект новой, транспанированной матрицы
	*/
	Matrix newMatrix(this->columns, this->lines);

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			newMatrix[j][i] = this->elements[i][j];

	return newMatrix;
}

bool squareType(const Matrix& matrix)
{
	/*!
		\brief Дружественная функция Определяет, является ли матрица квадратной, путём сравнения количества строк и столбцов
		\param matrix матрица, исследование которой проводится
		\return Булево значение true, если матрица квадратная и false в ином случае
	 */
	if (matrix.columns == matrix.lines)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool diagonalType(const Matrix& matrix, bool square)
{
	/*!
		\brief Дружественная функция Определяет, является ли матрица диагональной, путём сравнения количества нулей в матрице
		\details матриа называется диагональной, если все е1 элементы, кроме главной диагонали равны нулю
		\param matrix матрица, исследование которой проводится
		\return Булево значение true, если матрица квадратная и false в ином случае
	 */
	if (!square)
	{
		return false;
	}
	else
	{
		int zeros = 0;
		for (int i = 0; i < matrix.lines; i++)
		{
			for (int k = 0; k < matrix.columns; k++)
			{
				if (i == k)
				{
					continue;
				}

				if (matrix.elements[i][k] == 0)
				{
					zeros++;
				}
			}
		}

		if (zeros == matrix.lines * matrix.columns - matrix.columns)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool dentityType(const Matrix& matrix, bool diagonal)
{
	if (diagonal)
	{
		int ones = 0;
		int k = 0;
		for (int i = 0; i < matrix.lines; i++)
		{
			if (matrix.elements[i][k] == 1)
			{
				ones++;
			}
			k++;
		}

		if (ones == matrix.columns)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool nullType(const Matrix& matrix)
{
	for (int i = 0; i < matrix.lines; i++)
	{
		for (int k = 0; k < matrix.columns; k++)
		{
			if (matrix.elements[i][k] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool symmetricType(const Matrix& matrix, bool square)
{
	if (square)
	{
		for (int i = 0; i < matrix.lines; i++)
		{
			for (int j = 0; j < matrix.columns; j++)
			{
				if (i == j)
				{
					continue;
				}

				if (matrix.elements[j][i] != matrix.elements[i][j])
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool upTriangleType(const Matrix& matrix, bool square)
{
	if (square)
	{
		for (int i = 0; i < matrix.lines; i++)
		{
			for (int j = 0; j < matrix.columns; j++)
			{
				if (i > j && matrix.elements[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool downTriangleType(const Matrix& matrix, bool square)
{
	if (square)
	{
		for (int i = 0; i < matrix.lines; i++)
		{
			for (int j = 0; j < matrix.columns; j++)
			{
				if (i < j && matrix.elements[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

string Matrix::getMatrixType(const Matrix& matrix)
{
	/*!
		Метод возвращает строку, которая описывает тип матрицы (квадратная, диагональная, нулевая, единичная, симметрическая,
верхняя треугольная, нижняя треугольная)
	*/
	string result = "";
	bool square = squareType(matrix);
	bool diagonal = diagonalType(matrix, square);
	bool identity = dentityType(matrix, diagonal);
	bool nullM = nullType(matrix);
	bool symmetricM = symmetricType(matrix, square);
	bool upTriangle = upTriangleType(matrix, square);
	bool downTriangle = downTriangleType(matrix, square);

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

	if (result == "")
	{
		result = "None";
	}

	return "Matrix type is " + result + "\n";
}
