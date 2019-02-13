#include<iostream>
using namespace std;

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
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin >> A[i][j];
        }
    }
    if(magic(A,n)== 1)
        cout <<"true" << endl;
    else
        cout <<"false" << endl;
    return 0;
}
