#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    Matrix mat(3, 3);
    mat.print();
    ++mat;
    cout << endl;
    mat.print();
    mat++;
    mat.print();
    mat.setLinesNum(5);
    mat.print();
    mat.setColumnsNum(10);
    mat.print();
    mat.setLinesNum(3);
    mat.print();
    mat.setColumnsNum(3);
    mat.print();

    return 0;
}
