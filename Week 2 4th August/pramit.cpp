#include <iostream>
using namespace std;

void createMagicMatrix(int Matrix[5][5], int row, int col);
void displayMatrix(int row);

int main()
{
	int Matrix[5][5],row, col, i, j, k;

	cout << "Enter rows and column for matrix: ";
	cin >> row >> col;
		cout << "Enter rows and column for matrix: ";
		cin >> row >> col;
        createMagicMatrix(Matrix, row, col);
        displayMatrix(row);

	return 0;
}

void createMagicMatrix(int Matrix[5][5],int row, int col)
{
	int i, j;
	cout << endl << "Enter elements of matrix 1:" << endl;
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			cout << "Enter elements a"<< i + 1 << j + 1 << ": ";
			cin >> Matrix[i][j];
		}
	}
}
void displayMatrix(int row,int col)
{
	int i, j;
	cout << "Output Matrix:" << endl;
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			if(j == col - 1)
				cout << endl << endl;
		}
	}
}