#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int k, const int n, int i, int j);
void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max);
void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 10;
	int High = 40;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High, 0, 0);
	Print(a, k, n, 0, 0);
	int max;
	MaxMinRows(a, k, n, 1, max);
	cout << "MAX = " << max << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max)
{
	int min = a[rowNo][0];
	MinRow(a, rowNo, colCount, 1, min);
	if (min > max)
		max = min;
	if (rowNo < rowCount - 1)
		MaxMinRows(a, rowCount, colCount, rowNo + 2, max);
}

void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min)
{
	if (a[rowNo][colNo] < min)
		min = a[rowNo][colNo];
	if (colNo < colCount - 1)
		MinRow(a, rowNo, colCount, colNo + 1, min);
}

