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
    Matrix mat(12, 12);
    cout << mat;

    return 0;
}
