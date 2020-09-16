#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    Matrix mat(3, 3);
    Matrix mat2(mat);
    cout << mat;
    cout << mat2;

    return 0;
}
