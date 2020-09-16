/*!
\file
\brief Основной файл с использованием функционала класса Matrix
*/

#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    Matrix mat(4, 4);
    Matrix loaded = mat.loadMatrixFromFile("matrix.txt");
    cout << loaded;
    cout << loaded.getMatrixType();

    return 0;
}
