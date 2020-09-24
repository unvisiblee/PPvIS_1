#include "pch.h"
#include "CppUnitTest.h"
#include "../PPvIS_1/Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Matrix as(3, 4);
			Assert::IsTrue(as.getColumns() != as.getLines() != 0);
		}
	};
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			Matrix p(4, 4);
			p.setLinesNumber(2);
			Assert::IsTrue(p.getLines() == 2);
		}

		TEST_METHOD(TestMethod2)
		{

			Matrix p(4, 4);
			p.setColumnsNumber(2);
			Assert::IsTrue(p.getColumns() == 2);
		}

		TEST_METHOD(TestMethod3)
		{

			Matrix p(4, 4);
			Assert::IsTrue(isSquareType(p));
		}

		TEST_METHOD(TestMethod4)
		{

			Matrix p(3, 4);
			Assert::IsTrue(isSquareType(p) == false);
		}

		TEST_METHOD(TestMethod5)
		{
			Matrix as(3, 3);
			Assert::IsTrue(as.getColumns() == as.getLines());
		}

		TEST_METHOD(TestMethod6)
		{
			Matrix matrix(2, 2);
			for (int i = 0; i < matrix.getLines(); i++)
			{
				for (int k = 0; k < matrix.getColumns(); k++)
					matrix[i][k] = 0;
			}
			Assert::IsTrue(isNullType(matrix));
		}

		TEST_METHOD(TestMethod7)
		{
			Matrix matrix1(2, 2);
			Matrix matrix2;

			matrix2 = matrix1;

			Assert::IsTrue(matrix1 == matrix2);
		}

		TEST_METHOD(TestMethod8)
		{
			Matrix matrix1(2, 2);
			int nullElement = matrix1[0][0];
			matrix1--;
			Assert::IsTrue(nullElement - matrix1[0][0] == 1);
		}

	};
}