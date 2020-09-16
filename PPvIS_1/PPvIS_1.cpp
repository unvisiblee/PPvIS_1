#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    Matrix mat(2, 5);
    Matrix tranposed = mat.transpose();
    tranposed.print();
    //cout « mat.getMatrixType();
 
    return 0;
}
