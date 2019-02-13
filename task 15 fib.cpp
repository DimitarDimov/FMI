#include<iostream>
using namespace std;
int memo[1000] = {0};
//int calls = 0;
int fib(int n)
{
    //calls++;
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int fib_2(int n)
{
    //calls++;
    if(memo[n]!=0) return memo[n];
    if(n == 0) return 0;
    if(n == 1) return 1;
    memo[n] = fib_2(n-1) + fib_2(n-2);
    return memo[n];
}

int main()
{
    int n;
    cin >> n;
    //cout << fib(n) << endl;
    cout << fib_2(n) << endl;
   // cout<<calls;
    return 0;
}
