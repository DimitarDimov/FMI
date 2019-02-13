#include<iostream>
using namespace std;
void Print_down(int A[][5], bool down , int down_start, int down_end,int fixed)
{
    if(down == true)
    {
        if(down_start == down_end) { cout<< A[down_start][fixed];}
        for(int i = down_start; i < down_end; i++)
            cout << A[i][fixed]<<' ';
    }
    else
    {
        for(int i = down_start; i > down_end; i--)
        cout << A[i][fixed] <<' ';
    }
}
void Print_right(int A[][5],bool right,int right_start, int right_end, int fixed)
{
    if(right == true)
    {
        if(right_start == right_end) { cout<< A[right_start][fixed];}
        for(int j = right_start; j < right_end; j++)
            cout << A[fixed][j] <<' ';
    }
    else
    {
        for(int j = right_start; j > right_end; j--)
        cout << A[fixed][j] <<' ';
    }
}

void spirala_task3(int A[][5],int n)
{
    bool right = true;
    bool down = true;
    for(int i = 0, sum = 0 ; i <= n+3; i++, sum=(i/4))
    {
        if(i == 0 || i%4 == 0)
        {
            Print_down(A,true,sum,n-1-sum,sum);
        }
        if(i == 1 || i%4 == 1)
        {
            Print_right(A,true,sum,n-1-sum,n-1-sum);
        }
        if(i == 2 || i%4 == 2)
        {
            Print_down(A,false,n-1-sum,sum,n-1-sum);
        }
        if(i == 3 || i%4 == 3)
        {
            Print_right(A,false,n-1-sum,sum,sum);
        }
    }
    //Print_down(A,true,0,n-1,0);
    //Print_right(A,true,0,n-1,n-1);
    //Print_down(A,false,n-1,0,n-1);
    //Print_right(A,false,n-1,1,0);

//Print_down(A,true,1, n-2,1);
//Print_right(A,true,1,n-2,n-2);
//Print_down(A,false,n-2,1,n-2);
//Print_right(A,false,n-2,2,1);


}
void spirala_task4(int A[][5], int n)
{
    bool right = true;
    bool down = true;
    for(int i = 0, sum = 0 ; i <= n+3; i++, sum=(i/4))
    {
        if(i == 0 || i%4 == 0)
        {
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

bool magic(int A[][5], int n)
{

    for(int i = 0, sum = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum+= A[i][j];
        }
        if(sum!= n*(n*n+1)/2)
            return false;
        else sum = 0;
    }
    for(int j = 0, sum = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            sum+= A[i][j];
        }
        if(sum!= n*(n*n+1)/2)
            return false;
        else sum = 0;
    }
    int sum = 0;
    for(int i = 0;i < n; i++)
    {
        sum+= A[i][i];
    }
    if(sum!= n*(n*n+1)/2)
        return false;
    return true;
}
int main()
{
    int A[5][5],n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> A[i][j];
        }
    }
    //spirala_task3(A,n);
    spirala_task4(A,n);
    //if(magic(A,n)== 1)
        cout <<"true" << endl;
    //else
        cout <<"false" << endl;
    //return 0;
}
