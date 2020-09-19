/*!
\file
\author Орлов, Драгун, Насекайло (921701)
\brief Основной файл с использованием функционала класса Matrix
*/

#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void Menu(Matrix& mat)
{
/*!
    \brief меню для проверки функционала класса
    \details функции выбираются путём ввода числа из клавиатуры, соответсвующеие описанным в сообщении из консоли. Для этого используется цикл while. После каждого действия матрица выводится на жкран для наглядной проверки работы класса
    \param mat матрица, которая подвергается проверке
 */
    int mode = 0;

    while (true)
    {
        cout << mat;
        cout << "Choose what to do:\n1 - Exit\n2 - Operator ++ (postfix)\n3 - Operator ++ (prefix)\n4 - Operator -- (postfix)\n5 - Operator -- (prefix)\n6 - Operator ==\n7 - Operator []\n8 - Set number of lines\n9 - Set number of columns\n10 - extract SubMatrix\n11 - Transpose\n12 - get Matrix type\n";
        cin >> mode;

        if (mode == 1)
        {
            break;
        }

        if (mode == 2)
        {
            mat++;
        }

        if (mode == 3)
        {
            ++mat;
        }

        if (mode == 4)
        {
            mat--;
        }

        if (mode == 5)
        {
            --mat;
        }

        if (mode == 6)
        {

            cout << "You should create second matrix to compare with this\n";
            int create2;
            cout << "Choose how to init matrix:\n1 - Filling with random numbers\n2 - Loading from file\n3 - Filling manual\n";
            cin >> create2;
            Matrix mat3;

            if (create2 == 1)
            {
                cout << "Enter the number of columns: ";
                int columns2;
                cin >> columns2;
                cout << "and lines: ";
                int lines2;
                cin >> lines2;
                Matrix mat2(lines2, columns2);
                mat3 = mat2;
            }
            else if (create2 == 2)
            {
                Matrix mat2 = mat2.loadMatrixFromFile("matrix.txt");
                mat3 = mat2;
            }
            else if (create2 == 3)
            {
                cout << "Enter the number of columns: ";
                int columns2;
                cin >> columns2;
                cout << "and lines: ";
                int lines2;
                cin >> lines2;
                Matrix mat2(lines2, columns2);
                cin >> mat2;
                mat3 = mat2;
            }

            if (mat == mat3)
            {
                cout << "Mat1 == Mat2\n";
            }
            else
            {
                cout << "Mat1 != Mat2\n";
            }
            cout << mat;
            cout << mat3;
        }
        
        if (mode == 7)
        {
            int index1;
            int index2;
            cout << "Enter the index (lines, columns): ";
            cin >> index1;
            cin >> index2;
            if (mat.getLines() < index1 || mat.getColumns() < index2)
            {
                cout << "There is wrong index\n";
            }
            else
            {
                cout << "Here is your element: " << mat[index1][index2] << endl;
            }
        }

        if (mode == 8)
        {
            int numlines;
            cout << "Enter the number of lines: ";
            cin >> numlines;
            mat.setLinesNumber(numlines);
        }

        if (mode == 9)
        {
            int numcolumns;
            cout << "Enter the number of columns: ";
            cin >> numcolumns;
            mat.setLinesNumber(numcolumns);
        }

        if (mode == 10)
        {
            int sublines;
            int subcolumns;
            cout << "Enter the number of lines and columns of submatrix: ";
            cin >> sublines;
            cin >> subcolumns;
            try {
                mat = mat.extractSubMatrix(sublines, subcolumns);
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }

        if (mode == 11)
        {
            mat = mat.transpose();
        }

        if (mode == 12)
        {
            cout << mat.getMatrixType(mat);
        }
    }
}


int main()
{
/*!
 \brief Перед входом в меню нужно создать матрицу для последующих действий с ней
 /details описаны три вариантта создания матрицы: 1. Выбор размерности и заполнение ячеек случайными числами в диапазоне от -50 до +50
 2. Загрузка матрицы из существующего файла
 3. Выбор размерности матрицы и ручной поэлементный ввод из клавиатуры
 Далее происходит переход в ::Menu
*/
    srand(time(NULL));
    int create;
    cout << "Choose how to init matrix:\n1 - Filling with random numbers\n2 - Loading from file\n3 - Filling manual\n";
    cin >> create;

    if (create == 1)
    {
        cout << "Enter the number of columns: ";
        int columns;
        cin >> columns;
        cout << "and lines: ";
        int lines;
        cin >> lines;
        Matrix mat(lines, columns);
        Menu(mat);
    }
    else if (create == 2)
    {
        Matrix mat = mat.loadMatrixFromFile("matrix.txt");
        Menu(mat);
    }
    else if (create == 3)
    {
        cout << "Enter the number of columns: ";
        int columns;
        cin >> columns;
        cout << "and lines: ";
        int lines;
        cin >> lines;
        Matrix mat(lines, columns);
        cin >> mat;
        Menu(mat);
    }

    /*Matrix mat(2, 4);
    cout << mat;
    mat = mat.transpose();
    cout << mat;*/

    return 0;
}
