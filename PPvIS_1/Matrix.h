#pragma once
#include <string>
using namespace std;

class Matrix {
public:
	Matrix();
	~Matrix();
	void setRowsNum(unsigned int);  
	void setColumnsNum(unsigned int);
	Matrix* loadMatrixFromFile(const string&);
	Matrix* extractSubMatrix(unsigned int,unsigned int);
	string getMatrixType();
	Matrix* transpose();
private:
	// all other methods here
};
