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
    Matrix loaded = mat.loadMatrixFromFile("matrix.txt");
    loaded.print();
    cout << loaded.getMatrixType();
    
    return 0;
}
