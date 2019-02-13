#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> q;
int main()
{
int n,i,a;
cin>>n;
for(i=0;i<n;i++)
{
cin>>a;
q.push(a);
}
while(!q.empty())
{
a=q.top();
q.pop();
cout<<a<<' ';
}
cout<<endl;
return 0;
}