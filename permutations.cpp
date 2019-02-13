#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<char> s;
int p2n()
{
    int n,i,p;
    n = s.size();

    if(n>1)
    {
        vector<char>::iterator it = s.begin();
        i = find(s.begin(),s.end(),'a' + n -1) - it ;

        copy(s.begin()+i+1,s.begin()+n+1,s.begin()+i);

        p = p2n();
        if(p % 2 == 0)
            i = n - 1- i;
        return p*n+i;
    }
    else
        return 0;
    return p;
}
int fact(int n)
{
    if(n<= 1)
        return 1;
    else return n * fact(n-1);
}
bool result(string comp,char comp1[])
{
    for(int i = 0; i < comp.size();i++)
    {
        if(comp[i] != comp1[i])
            return false;
    }
    return true;
}
void gen_perm(string s1)
{
    char first[s1.size()];
    for(int i = 0; i < s1.size();i++)
    {
        first[i] = char((int)'a' + i);
    }

    int counter = 0,n = s1.size();
    bool left = true;

   for(int i = 0,j = 1; i < fact(n);i++,j++)
    {
        //cout << first[0]<<first[1]<<first[2]<<first[3]<<' '<<i<<endl;
       if(result(s1,first)) cout << i;
        if((i+1) % 8 == 0)
        {
            swap(first[0],first[1]);
            left = true;
            j = 0;
            continue;
        }
        else
        if((i+1) % 4 == 0)
        {
            left = false;
            j = -1;
            swap(first[n-1], first[n-2]);
            continue;

        }

        if(left)
        {
            swap(first[n - j],first[n - j - 1]);

        }
        else
        {
            swap(first[j],first[j+1]);

        }

    }
}
int main()
{
    string v = "bcda";
    for(int i = 0; i < v.size();i++)
    {
        s.push_back(v[i]);
    }

    //cout<< p2n();
   gen_perm(v);
    return 0;
}
