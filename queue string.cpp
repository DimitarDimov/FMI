#include<iostream>
#include<string>
#include<queue>
using namespace std;
priority_queue<string>q;
int main()
{
    int n,i;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        q.push(s);
    }
    while(!q.empty())
{
    s=q.top();
    q.pop();
    cout<<s<<' ';
}
cout<<endl;
return 0;
}