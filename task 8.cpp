#include<iostream>
using namespace std;
void Print_down(int A[][5], bool down , int down_start, int down_end,int fixed)
{
    if(down == true)
    {
        if(down_start == down_end)
        {
             cout<< A[down_start][fixed];
        }
        for(int i = down_start; i < down_end; i++)
        {
            cout << A[i][fixed]<<' ';
        }
    }
    else
    {
        for(int i = down_start; i > down_end; i--)
        {
            cout << A[i][fixed] <<' ';
        }
    }
}

void Print_right(int A[][5],bool right,int right_start, int right_end, int fixed)
{
    if(right == true)
    {
        if(right_start == right_end)
        {
             cout<< A[right_start][fixed];
        }
        for(int j = right_start; j < right_end; j++)
        {
            cout << A[fixed][j] <<' ';
        }
    }
    else
    {
        for(int j = right_start; j > right_end; j--)
        {
            cout << A[fixed][j] <<' ';
        }
    }
}

void spirala_task4(int A[][5], int n)
{
    bool right = true;
    bool down = true;
    for(int i = 0, sum = 0 ; i <= n+3; i++, sum=(i/4))
    {
        if(i == 0 || i%4 == 0)
        {
            if(i == 0)
            {
                Print_right(A,true,sum,n-sum,sum);
            }
            else
            Print_right(A,true,sum,n-1-sum,sum);
        }
        if(i==1 || i%4==1)
        {
            if(i==1)
            {
                Print_down(A,true,1,n-1,n-1-sum);
            }
            else
                Print_down(A,true,1,n-2,n-1-sum);

        }

        if(i == 2 || i%4 == 2)
        {
            if(i == 2)
            {
                Print_right(A,false,n-1-sum,sum,n-1-sum);
            }
            else
                Print_right(A,false,n-1-sum,sum-1,n-1-sum);
        }
        if(i == 3 || i%4 == 3)
        {
            Print_down(A,false,(n-1-(2*sum)),sum,sum);
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
    spirala_task4(A,n);
    return 0;
}
