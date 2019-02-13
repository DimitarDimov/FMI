#include<iostream>
using namespace std;

void first_task(int A[][5], int n)
    {

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0, ch = 0; j <= i ; j++,ch++)
            {
                cout << A[i-ch][j]<<' ';
            }
        }

        for(int count = 0, i = n-1; i > 0; i--, count++)
        {
            for( int j = 1 + count, ch = 0; j <= n-1; j++, ch++)
            {
                cout << A[n-1-ch][j]<<' ';
            }
        }
    }

 int main()
    {
        int A[5][5],n;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
                {
                    cin >> A[i][j];
                }
        }
    first_task(A,n);
    return 0;
}
