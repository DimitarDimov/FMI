#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void swap_eq(char a[],int p,int q,int m)
{
    for(;m;++p,++q,--m)
    {
        swap(a[p],a[q]);
    }
}
void swap_non_eq(char a[],int p, int m, int n)
{
    int q;
    while(m!=n)
    {
        if(m<n)
        {   swap_eq(a,p,p+n,m);
            n-=m;
        }
        else
        {
            swap_eq(a,p,p+m,n);
            p+=n;
            m-=n;
        }
    }
    swap_eq(a,p,p+m,m);
}

int binsearch(int a[],int p,int n,int x)
{
    int h,m;
    for(;;)
    {
        if(n <= 1)
        {
            return p += (n==1) && (a[p]<x);
        }
        h = n/2;
        m = p+h;
        if(x <= a[m])
        {
             n = h;
        }
        else
        {
            p = m;
            n -= h;
        }
    }
}

void permcode(unsigned a[],unsigned n)
{   int i,j;
    for(i = n-1; i > 0;i--)
    {
        for(j = i-1; j>=0;j--)
            if(a[j]>a[i])
            a[j]--;
    }
    for(i = 0; i < n; i++)
    a[i] = i+1 - a[i];
}
void permdecode(unsigned a[],unsigned n)
{   int i,j;
    for(i = 0; i < n;i++)
        a[i] = i+1 -a[i];
    for(i = 1; i < n; i++)
        for(j = 0; j < i;j++)
    {
        if(a[j]>=a[i])
            a[j]++;
    }
}

bool consist(int a, int b, int x)
{
    int mini = min(a,b);
    int maxi = max(a,b-1);
    for(int i = mini;i < maxi;i++)
    {
        if(i == x) return true;
    }
    return false;
}
vector<int> a;

void perm(int n)
{
    if(--n)
    {
        for(int i = 0; i < n;i++)
        {
            perm(n);
            if(i == n)
                break;
            swap(a[i],a[n]);
        }
        rotate(a.begin(),a.begin()+1,a.end());
    }
    for(vector<int>:: iterator it = a.begin(); it != a.end();it++)
        cout <<*it<<' ';
    cout <<endl;
}
string s="abcd";

void n2p(int n,int p)
{   int q,i;
    if(n > 1)
    {   q = p/n;
        i = p % n;
        if(q % 2 == 0)
            i = n -1 -i;
        n2p(n-1,q);
        copy_backward(s.begin()+i,s.begin()+n, s.begin()+n+1);
        s[i] ='a' +n -1;
    }
    else s ="a";

}
/*
int p2n()
{
    int n,i,p;
    n = s.size();
    if(n >1)
    {
        i = s.find('a'+n-1) - s.begin();
        copy(s.begin()+i+1, s.begin()+n+1,s.begin()+i);
        p = p2n();
        if(p%2==0)
        {
            i = n-1-i;
        }
        return p*n+i;
    }
    else return 0;
    return p;
}
*/
int bs(int a[],int p,int n, int x)
{
    int h,m;
    while(1)
    {
        if(n <= 1)
        {
            return p+= (n==1) && (a[p]<x);
        }
        h = n/2;
        m = p+h;
        if(x <= a[m])
        {
            n = h;
        }
        else
        {
            p = m;
            n -= h;
        }
    }
}




int main()
{
    //cout << consist(2,8,5);
    /* char s[]="harrystudents";
    swap_non_eq(s,0,5,8);
    for(int i = 0; i < 13;i++)
    {
        cout << s[i] << ' ';
    }
    */
    int arr[]={1,2,3,4,5,6,7,8};
    cout << bs(arr,0,8,7);
    /*unsigned arr[] = {0,1,1,1,3,5,4};
    unsigned arr1[] = {7,2,5,6,4,1,3};
    permcode(arr1,7);
    permdecode(arr,7);
    for(int i = 0; i < 7; i++)
        cout <<arr[i]<<' ';
    //cout << binsearch(arr,0,10,1);
    */
    for(int i =1;i < 5;i++)
{
    a.push_back(i);
}
    //perm(4);
  //  n2p(4,17);
    //for(int i = 0; i < 4; i++)
    //cout <<s[i];

    return 0;
}
