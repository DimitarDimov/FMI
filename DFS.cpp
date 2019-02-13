#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int>v[1024];
int used[1024];
void read23()
{
    int i,j,x,y;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}   
void DFS(int i)
{
	used[i]=1;
	int cn,j;
	cn=v[i].size();
	for(j=0;j<cn;j++)
	if(!used[v[i][j]])
	DFS(v[i][j]);
}
int main()
{
    int br=0,i;
    read23();
    for(i=1;i<=n;i++)
    if(!used[i]){br++;DFS(i);}
    cout<<br<<endl;
    return 0;
}