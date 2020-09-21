/*!
\file
\brief Файл с описанием функционала класса Matrix
*/
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*!
	\brief Конструктор по умолчанию, который устанавливает начальное положение объекта. Не принимает параметров
 */
Matrix::Matrix()
{
	columns = 0;
	lines = 0;
	elements = nullptr;
}

/*!
	Конструктор принимает количество строк и столбцов матрицы и заполняет их нулями
	\param lines количество строк в содаваемой матрице
	\param columns количество столбцов в создаваемой матрице
*/
Matrix::Matrix(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;

	elements = new int* [lines];
	for (int i = 0; i < lines; i++)
		elements[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] = 0;

}

/*!
	Конструктор принимает количество строк и столбцов матрицы и заполняет их случайными числами в диапазоне от from до to
	\param lines количество строк в содаваемой матрице
	\param columns количество столбцов в создаваемой матрице
	\param from нижняя граница диапазона случайных чисел, которыми заполняется матрица
	\param to верхняя граница диапазона случайных чисел, которыми заполняется матрица
*/
Matrix::Matrix(int lines, int columns, int from, int to)
{
	to++;
	int randomInt = to + fabs(from);
	this->lines = lines;
	this->columns = columns;

	elements = new int* [lines];
	for (int i = 0; i < lines; i++)
		elements[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] = rand() % randomInt - fabs(from);

}

/*!
	Конструктор копирования создаёт новый объект и копирует в него другой, избегая проблем с памятью
	\param other ссылка на второй объект копирования
*/
Matrix::Matrix(const Matrix& other) 
{
	
	columns = other.columns;
	lines = other.lines;

	elements = new int* [lines];
	for (int i = 0; i < lines; i++)
		elements[i] = new int[columns];

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] = other.elements[i][k];

}
/*!
	\brief Очистка динамической памяти, занятой матрицой
	\param matrix матрица, память которой удаляется
*/
void Matrix::clean(Matrix& matrix)
{
	if (matrix.lines > 0)
	{
		for (int i = 0; i < matrix.lines; i++)
		{
			delete[]matrix.elements[i];
		}
	}

	if (columns > 0)
	{
		delete[]matrix.elements;
	}
}

/*!
	Деструктор освобождает память, выделенную для матрицы. Не принимает параметров
*/
Matrix::~Matrix()
{
	clean(*this);
}

/*!
	Геттер для получения количества строк данной матрицы. Не принимает параметров
	\return Количество строк данной матрицы
*/
int Matrix::getLines()
{
	return this->lines;
}

/*!
	Геттер для получения столбцов данной матрицы. Не принимает параметров
	\return Количество столбцов данной матрицы
*/
int Matrix::getColumns()
{
	return this->columns;
}

/*!
	Перегрузка потокового оператора для вывода матрицы в консоль
	\return объект типа ostream, который выводится на экран
	\param os ссылка на объект типа ostream, который выводится на экран
	\param matrix матрица, которая выводится на экран
*/
ostream& operator<<(ostream& os, const Matrix& matrix)
{
	cout << "-----------\n";
	for (int i = 0; i < matrix.lines; i++)
	{
		for (int k = 0; k < matrix.columns; k++)
			os << matrix.elements[i][k] << "\t";

		os << endl << endl;
	}

	return os;
}

/*!
	Перегрузка потокового оператора для ввода матрицы вручную
	\param in объект типа istream, который принимает в себя значения, считываемые из клавиатуры при вводе в консоли
	\param matrix матрица, элементы которой вводятся
	\return объект типа istream, который заполняет матрицу вводёнными числами
*/
istream& operator>>(istream& in, Matrix& matrix)
{
	cout << "Fill in the matrix: \n";
	for (int i = 0; i < matrix.lines; i++) {
		for (int k = 0; k < matrix.columns; k++)
			in >> matrix.elements[i][k];
	}
	return in;
}

/*!
	Перегрузка оператора присваивания передаёт элементы одной матрицы в соответсвующие индексы другой
	\param other второй объект типа матрица в операции присваивания
	\return разыменованный указатель на данную матрицу
	\details в ходе выполнения функции выполняется освобождение памяти старого объекта и выделяется новая память. Элементы поиндексно переносятся из other в this
*/
Matrix Matrix::operator=(const Matrix& other)
{
	clean(*this);

	lines = other.lines;
	columns = other.columns;
	elements = new int* [lines];
	for (int i = 0; i < lines; i++)
		elements[i] = new int[columns];	

	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			elements[i][j] = other.elements[i][j];

	return *this;
}

/*!
	Префиксный инкремент увеличивает каждый элемент матрицы на единицу
	\return Разыменованный указатель на данную матрицу
*/
Matrix& Matrix::operator++()
{
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k]++;

	return *this;
}

/*!
	Постфиксный инкремент увеличивает каждый элемент матрицы на единицу
	\return Разыменованный указатель на данную матрицу
	\param number нужен для отличия от префиксного инкремента, согласно документации с++
*/
Matrix& Matrix::operator++(int number)
{
	Matrix temp = *this;

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k]++;

	return *this;
}

/*!
	Префиксный декремент уменьшает каждый элемент матрицы на единицу
	\return Разыменованный указатель на данную матрицу
*/
Matrix& Matrix::operator--()
{	
	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] -= 1;

	return *this;
}

/*!
	Префиксный декремент уменьшает каждый элемент матрицы на единицу
	\return Разыменованный указатель на данную матрицу
	\param number нужен для отличия от префиксного декремента, согласно документации с++
*/
Matrix& Matrix::operator--(int number)
{
	Matrix temp = *this;

	for (int i = 0; i < lines; i++)
		for (int k = 0; k < columns; k++)
			elements[i][k] -= 1;

	return *this;
}

/*!
	Перегрузка оператора сравнения осуществляется поэлементный сравнением матриц (соответствующих индексов)
	\param other ссылка на вторую матрицу в сравнении на равенство
	\return возвращает true, если матрицы равны и false в ином случае
*/
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
			if (this->elements[i][k] != other.elements[i][k])
			{
				return false;
			}
		}
	}
	
	return true;
}

/*!
	Перегрузка оператора [] для доступа к элементу матрицы по индексу
	\return Массив значений строки матрицы заданного индекса
	\param index индекс строки матрицы
	\details впоследствии можно применить еще один оператор [] для получения конкретного элемента, а не целой строки
*/
int* Matrix::operator[](unsigned int index)
{
	if (index > this->lines || index < 0)
		throw "Index is out of bounds!";
	else return this->elements[index];
}

/*!
	Изменение количества строк матрицы
	\param newLinesNumber число строк в новой матрице
	\details в ходе выполнения метода создаётся новая матрица, элементы с одинаковым индексом от предыдущей матрицы остаются теми же. В дополнительные ячейки, если введено число строк, превосходящее число строк изначальной матрицы, помещяются нули
*/
void Matrix::setLinesNumber(unsigned int newLinesNumber)
{
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

/*!
	Изменение количества столбцов матрицы
	\param newColumnsNumber число столбцов в новой матрице
	\details в ходе выполнения метода создаётся новая матрица, элементы с одинаковым индексом от предыдущей матрицы остаются теми же. В дополнительные ячейки, если введено число столбцов, превосходящее число столбцов изначальной матрицы, помещяются нули
*/
void Matrix::setColumnsNumber(unsigned int newColumnsNumber)
{
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

/*!
	\briefЗагрузка матрицы из файла
	\details файл представляет собой набор чисел, первые два которые означают число строк и столбцов матрицы, а последующие элементы матрицы, записанные через пробел и переносы строк, соответсвенно строкам и столбцам получаемой матрицы
	\param filepath константная строка передаётся по ссылке, содержащая путь (имя) файла, из которого считывается матрица
	\return объект матрицы, считанной из файла
*/
Matrix Matrix::loadMatrixFromFile(const string& filepath)
{
	
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

/*!
	\details Новая матрицы получается путём "обрезания" данной. Элементы и индексы сохраняются, если они соответсвуют новым заданным размерам
	\brief Извлекает подматрицу заданных размеров
	\param lines число строк новой матрицы
	\param columns число столбцов новой матрицы
	\return объект матрицы, которая является подматрицей исходной матрицы
*/
Matrix Matrix::extractSubMatrix(unsigned int lines, unsigned int columns)
{
	if (lines > this->lines || columns > this->columns || lines <= 0 || columns <= 0)
		throw "Index out of bounds!";

	Matrix newMatrix(lines, columns);

	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			newMatrix[i][j] = elements[i][j];

	return newMatrix;
}

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
Matrix Matrix::transpose()
{
	Matrix newMatrix(this->columns, this->lines);

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			newMatrix[j][i] = this->elements[i][j];

	return newMatrix;
}

/*!
	\brief Дружественная функция Определяет, является ли матрица квадратной, путём сравнения количества строк и столбцов
	\param matrix матрица, исследование которой проводится
	\return Булево значение true, если матрица квадратная и false в ином случае
*/
bool isSquareType(const Matrix& matrix)
{
	return matrix.columns == matrix.lines;
}

/*!
	\brief Дружественная функция Определяет, является ли матрица диагональной, путём сравнения количества нулей в матрице
	\details матрица называется диагональной, если она квадратная и все её элементы, кроме главной диагонали, равны нулю
	\param matrix матрица, исследование которой проводится
	\param square булево значение, является ли матрица квадратной
	\return Булево значение true, если матрица диагональная и false в ином случае
*/
bool isDiagonalType(const Matrix& matrix)
{
	if (!isSquareType(matrix))
	{
		return false;
	}

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

	return false;
}

/*!
	\brief Дружественная функция Определяет, является ли матрица единичной, путём сравнения единиц в диагональной матрице
	\details матрица называется единичной, если она диагональная и все её элементы на главной диагонали равны единице
	\param matrix матрица, исследование которой проводится
	\param diagonal булево значение, диагональная ли матрица
	\return Булево значение true, если матрица единичная и false в ином случае
*/
bool isIdentityType(const Matrix& matrix)
{
	if (!isDiagonalType(matrix))
	{
		return false;
	}
			
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

	return false;
}

/*!
	\brief Дружественная функция Определяет, является ли матрица нулевой, путём сравнения количества нулей в матрице
	\details матрица называется нулевой, если все её равны нулю
	\param matrix матрица, исследование которой проводится
	\return Булево значение true, если матрица нулевая и false в ином случае
*/
bool isNullType(const Matrix& matrix)
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

/*!
	\brief Дружественная функция Определяет, является ли матрица симметричной, путём сравнения елементов с обратными индексами
	\details матрица называется симметричной, если транспанированная матрица равна исходной
	\param matrix матрица, исследование которой проводится
	\param square булево значения, является ли матрица квадратной
	\return Булево значение true, если матрица симметричная и false в ином случае
*/
bool isSymmetricType(const Matrix& matrix)
{
	if (!isSquareType(matrix))
	{
		return false;
	}
	
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

	return true;
}

/*!
	\brief Дружественная функция Определяет, является ли матрица верхней треугольной, путём сравнения елементов выше главой диагонали с нулём
	\details матрица называется верхней треугольной, если её элементы ниже главной диагонали равны нулю
	\param matrix матрица, исследование которой проводится
	\param square булево значения, является ли матрица квадратной
	\return Булево значение true, если матрица верхняя треугольная и false в ином случае
*/
bool isUpTriangleType(const Matrix& matrix)
{
	if (!isSquareType(matrix))
	{
		return false;
	}
	
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
	
	return true;
}

/*!
	\brief Дружественная функция Определяет, является ли матрица нижней треугольной, путём сравнения елементов ниже главой диагонали с нулём
	\details матрица называется верхней треугольной, если её элементы выше главной диагонали равны нулю
	\param matrix матрица, исследование которой проводится
	\param square булево значения, является ли матрица квадратной
	\return Булево значение true, если матрица нижняя треугольная и false в ином случае
*/
bool isDownTriangleType(const Matrix& matrix)
{
	if (!isSquareType(matrix))
	{
		return false;
	}	

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

	return true;
}

/*!
	\brief определяет тип матрицы
	\details возможные типы: квадратная, диагональьная, единичная, нулевая, верхняя треугольная, нижняя треугольная, симметричная либо ни одна из перечсиленных
	\param matrix матрица, исследование которой производится
	\return строку, которая содержит информацию о типе переданой матрицы
*/
string Matrix::getMatrixType(const Matrix& matrix)
{
	string result = "";
	bool square = isSquareType(matrix);
	bool diagonal = isDiagonalType(matrix);
	bool identity = isIdentityType(matrix);
	bool nullM = isNullType(matrix);
	bool symmetricM = isSymmetricType(matrix);
	bool upTriangle = isUpTriangleType(matrix);
	bool downTriangle = isDownTriangleType(matrix);

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
