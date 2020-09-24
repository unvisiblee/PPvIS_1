#include "pch.h"
#include "CppUnitTest.h"
#include "../PPvIS_1/Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(constructorWithParameters)
		{
			Matrix matrix(3, 4);
			Assert::IsTrue(matrix.getColumns() != matrix.getLines() != 0);
		}

		TEST_METHOD(constructor)
		{
			Matrix matrix;
			Assert::IsTrue(matrix.getColumns() == 0);
		}

		TEST_METHOD(setLinesNumber)
		{
			Matrix matrix(5, 5);
			matrix.setLinesNumber(3);
			Assert::IsTrue(matrix.getLines() == 3);
		}

		TEST_METHOD(setColumnsNumber)
		{
			Matrix matrix(5, 5);
			matrix.setColumnsNumber(3);
			Assert::IsTrue(matrix.getColumns() == 3);
		}
	};
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(identityTypeMatrix)
		{

			Matrix matrix1(3, 3);
			matrix1[0][0] = 1, matrix1[0][1] = 0, matrix1[0][2] = 0;
			matrix1[1][0] = 0, matrix1[1][1] = 1, matrix1[1][2] = 0;
			matrix1[2][0] = 0, matrix1[2][1] = 0, matrix1[2][2] = 1;
			Assert::IsTrue(isIdentityType(matrix1));
		}

		TEST_METHOD(diagonalTypeMatrix)
		{

			Matrix matrix1(3, 3, 5, 6);
			matrix1[0][0] = 9, matrix1[0][1] = 0, matrix1[0][2] = 0;
			matrix1[1][0] = 0, matrix1[1][1] = 6, matrix1[1][2] = 7;
			matrix1[2][0] = 0, matrix1[2][1] = 0, matrix1[2][2] = 1;
			Assert::IsFalse(isDiagonalType(matrix1));
		}

		TEST_METHOD(squareTypeMatrix)
		{

			Matrix matrix(4, 4);
			Assert::IsTrue(isSquareType(matrix));
		}

		TEST_METHOD(squareTypeMatrix2)
		{

			Matrix matrix(3, 4);
			Assert::IsFalse(isSquareType(matrix));
		}

		TEST_METHOD(getColumnsMatrix)
		{
			Matrix matrix(3, 3);
			Assert::IsTrue(matrix.getColumns() == matrix.getLines());
		}

		TEST_METHOD(nullTypeMatrix)
		{
			Matrix matrix(2, 2);
			for (int i = 0; i < matrix.getLines(); i++)
			{
				for (int k = 0; k < matrix.getColumns(); k++)
					matrix[i][k] = 0;
			}
			Assert::IsTrue(isNullType(matrix));
		}

		TEST_METHOD(operatorEqually)
		{
			Matrix matrix1(2, 2);
			Matrix matrix2;

			matrix2 = matrix1;

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(operatorMinus)
		{
			Matrix matrix1(2, 2);
			int nullElement = matrix1[0][0];
			matrix1--;
			Assert::IsTrue(nullElement - matrix1[0][0] == 1);
		}
		TEST_METHOD(operatorPlus)
		{
			Matrix matrix1(2, 2);
			int nullElement = matrix1[0][0];
			matrix1++;
			Assert::IsTrue(nullElement - matrix1[0][0] == -1);
		}
		TEST_METHOD(extractSubMatr)
		{
			Matrix matrix1(5, 5);
			Matrix matrix2 = matrix1.extractSubMatrix(2, 3);
			bool f = true;
			for (int i = 0; i < matrix2.getLines(); i++)
			{
				for (int k = 0; k < matrix2.getColumns(); k++)
				{
					if (matrix1[i][k] != matrix2[i][k])
					{
						f = false;
					}
				}
			}

			Assert::IsTrue(matrix2.getLines() == 2 && matrix2.getColumns() == 3);
		}

		TEST_METHOD(diagonalTypeMatrix2)
		{
			Matrix matrix1(3, 3, 8, 9);
			matrix1[0][0] = 2, matrix1[0][1] = 0, matrix1[0][2] = 0;
			matrix1[1][0] = 0, matrix1[1][1] = 7, matrix1[1][2] = 0;
			matrix1[2][0] = 0, matrix1[2][1] = 0, matrix1[2][2] = 9;
			Assert::IsTrue(isDiagonalType(matrix1));
		}

	};
}
