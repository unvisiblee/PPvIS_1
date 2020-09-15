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
    mat.setLinesNum(5);
    mat.print();
    mat.setColumnsNum(5);
    mat.print();
    mat.transpose();
    mat.print();
    Matrix test = mat.extractSubMatrix(2, 6);
    test.print();
    

    return 0;
}
