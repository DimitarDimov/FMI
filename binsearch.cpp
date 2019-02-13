#include<iostream>
using namespace std;

int binSearch(int a[], int start, int n, int x)
{
    int half, mid;
    while(n > 0)
    {
        half = n / 2;
        mid = half + start;
        //if(x == a[start]) return start;
        //if(x == a[n-1]) return n-1;
        if(x == a[mid]) return mid;

        if(x <= a[mid]) n = mid;
        else
        {
            start = half;
            n -= half;
        }

    }
    return -1;
}




int main()
{
    int a[] = {12, 22, 34, 47, 55, 67, 82, 98};
    cout << binSearch(a, 0, 8, 47);

    return 0;
}
