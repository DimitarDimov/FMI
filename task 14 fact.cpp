#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    char st[101];
    int n = 0;
    cin.getline(st,100);
    for(int i = 0; i < strlen(st); i++)
    {
        if(st[i] >= '0' && st[i]<='9' )
        {
            n+= pow(10.0, double(i))*(st[i] - '0');
            if(st[i] == '0')
            {
                n*=10;
            }
        }
    }
    cout << fact(n) << endl;
    return 0;
}
