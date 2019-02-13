#include <iostream>
using namespace std;

void construct(int A[][15], int n)
{
	int row = 0, col = n/2, secRow = 0, secCol = 0;
	for (int i = 1;i <= n*n;i++)
	{
		A[row][col] = i;

			if ( row - 1   < 0 )
				secRow = n - 1;
			else
				secRow = row - 1;

			if (col + 1 > n - 1)
				secCol = 0;
			else
				secCol = col + 1;

		if ( A[secRow][secCol] != 0)
			{
				row = row + 1;
			}
		else
			{
				row = secRow;
				col = secCol;
			}
	}
}

void print(int A[][15], int n)
{
	for (int i = 0;i < n;i++)
	{
	    cout << "  ";
		for (int j = 0;j < n;j++)
		{
		    if(A[i][j]<10)
            {
                cout << ' ';
            }
			cout  << A[i][j] <<"  ";
		}
		cout << endl;
	}
}
int main ()
{
	int A[15][15] = {0};
	int n;
	cout <<"Enter number: ";
	cin >> n;
    while(n % 2 == 0 || n <= 1)
    {
        cout <<"Invalid Input! Enter new: ";
        cin >> n;
    }
    construct(A,n);
	print(A,n);
	return 0;
}
