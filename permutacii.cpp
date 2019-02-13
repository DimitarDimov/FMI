#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
void reversePosition(int []arr,int n,int pos)
{
    for(int i =0; i < pos;++i)
    {
        for(int j =0; j < n;++j)
        {
            swap(arr[j],arr[j+1]);
        }
    }
}
*/
string s; vector<int> arr;
void n2p(int n, int p)
{
    int q,i;
    arr.push_back(0);
    if(n > 1)
    {
        q = p / n;
        i = p % n;
        if(q % 2 == 0)
            i = n - 1 - i;
        n2p(n-1,q);
        //copy_backward(s.begin()+i, s.begin()+n, s.begin()+n+1);
        s[i] = 'a' + n -1;
        arr[i] == 1;
     }
    else
        for(i = 0; i < arr.size();i++)
    {
        if(arr[i] == 0) s[i] = 'a';
    }
    //s = "a";

}
int p2n()
{
    int n,i,p;
    n = s.size();
    if(n > 1)
    {
        i = find('a' + n -1) - s.begin();
        copy(s.begin()+i+1, s.begin()+n+1,s.begin()+i);
        p = p2n();
        if(p %  2 == 0)
            i = n - 1 - i;
        return p * n + i;
    }
    else
        return 0;
        cout <<1;
    return p;
}
int main()
{
    int arr[]={1,2,3,4,5};
   // reversePosition(arr,5,3);
    for(int i = 0; i < 5;i++)
    {
     //   cout << arr[i] << ' ';
    }
    cout << endl;
    n2p(4,17);
    for(int i  = 0; i < 4;i++)
    {
        cout << s[i] <<' ';
    }
    p2n();
    return 0;
}
