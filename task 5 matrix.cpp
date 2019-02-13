#include<iostream>
using namespace std;

void second_task(int A[][5], int n)
    {

        for(int i = 0, count = n-1 ; i < n; i++, count--)
        {
            for(int j = n-1, ch = 0; j >= count ; j--,ch++)
            {

                cout << A[ch][count+ch]<<' ';

            }
        }

        for(int i = 0 ; i < n; i++)
        {
            for(int j = n-1-i, ch = 0; j > 0 ; j--,ch++)
            {
                cout << A[i+ch+1][ch]<<' ';
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
    second_task(A,n);
    return 0;
    }
