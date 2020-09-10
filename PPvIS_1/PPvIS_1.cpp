#include <iostream>
#include "Matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    Matrix mat(3, 3);
    mat.Print();
    ++mat;
    cout << endl;
    mat.Print();
    mat++;
    mat.Print();

    return 0;
}
