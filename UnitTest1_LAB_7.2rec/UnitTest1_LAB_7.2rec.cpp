#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_7.2.rec/lab_7.2.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1LAB72rec
{
	TEST_CLASS(UnitTest1LAB72rec)
	{
	public:
        TEST_METHOD(TestMethod1)
		{
            int rowCount = 8;
            int colCount = 5;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
            {
                a[i] = new int[colCount];
                for (int j = 0; j < colCount; j++)
                {
                    a[i][j] = 1;
                }
            }

            int max; 
            MaxMinRows(a, rowCount, colCount, 1, max);
            Assert::AreEqual(1, max);
            for (int i = 0; i < rowCount; i++)
            {
                delete[] a[i];
            }
            delete[] a;

		}
	};
}
