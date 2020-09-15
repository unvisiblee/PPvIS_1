#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    Matrix mat(2, 2);
    mat.print();
    //Matrix loaded = mat.loadMatrixFromFile("matrix.txt");
    cout << mat.getMatrixType();
 
    return 0;
}
