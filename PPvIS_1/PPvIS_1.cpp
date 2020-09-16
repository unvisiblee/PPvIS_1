/*!
\file
\brief Основной файл с использованием функционала класса Matrix
*/

#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void Menu(Matrix& mat)
{
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
            Matrix mat2(2, 2);

            if (create2 == 1)
            {
                cout << "Enter the number of columns: ";
                int columns2;
                cin >> columns2;
                cout << " and lines: ";
                int lines2;
                cin >> lines2;
                Matrix mat2(lines2, columns2);
            }
            else if (create2 == 2)
            {
                Matrix mat2 = mat2.loadMatrixFromFile("matrix.txt");
            }
            else if (create2 == 3)
            {
                cout << "Enter the number of columns: ";
                int columns2;
                cin >> columns2;
                cout << " and lines: ";
                int lines2;
                cin >> lines2;
                Matrix mat2(lines2, columns2);
                cin >> mat2;
            }

            if (mat == mat2)
            {
                cout << "Mat1 == Mat2\n";
            }
            else
            {
                cout << "Mat1 != Mat2\n";
            }
            cout << mat;
            cout << mat2;
        }

        if (mode == 7)
        {
            int index1;
            int index2;
            cout << "Enter the index (lines, columns): ";
            cin >> index1;
            cin >> index2;
            cout << "Here is your element: " << mat[index1][index2] << endl;
        }

        if (mode == 8)
        {
            int numlines;
            cout << "Enter the number of lines: ";
            cin >> numlines;
            mat.setLinesNum(numlines);
        }

        if (mode == 9)
        {
            int numcolumns;
            cout << "Enter the number of columns: ";
            cin >> numcolumns;
            mat.setLinesNum(numcolumns);
        }

        if (mode == 10)
        {
            int sublines;
            int subcolumns;
            cout << "Enter the number of lines and columns of submatrix: ";
            cin >> sublines;
            cin >> subcolumns;
            mat.extractSubMatrix(sublines, subcolumns);
        }

        if (mode == 11)
        {
            mat = mat.transpose();
        }

        if (mode == 12)
        {
            cout << mat.getMatrixType();
        }
    }
}

int main()
{
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


    return 0;
}
