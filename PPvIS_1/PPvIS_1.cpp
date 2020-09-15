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
    string type = mat.getMatrixType();
    cout << type;

    return 0;
}
