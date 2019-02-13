#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#pragma comment (linker, "/STACK:16777216")
using namespace std;
int n,m,root[65536],level[65536],h,dist[65536],used[65536],l,sq,pf[65536];
struct edge
{
    int dis,e;
};
vector<edge> v[65536];
void read()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<n;++i)
    {
        int x,y,z;
        edge p;
        scanf("%d%d%d",&x,&y,&z);
        p.e=y;
        p.dis=z;
        v[x].push_back(p);
        p.e=x;
        v[y].push_back(p);
    }
    scanf("%d",&m);
}
void dfs_fill(int i)
{
    used[i]=1;
    level[i]=l;
    if(l>h)
    h=l;
    int sz=v[i].size(),j;
    for(j=0;j<sz;++j)
    if(!used[v[i][j].e])
    {
        l++;
        dist[v[i][j].e]=dist[i]+v[i][j].dis;
        root[v[i][j].e]=i;
        dfs_fill(v[i][j].e);
        l--;
    }
}
void dfs_par(int i)
{
    used[i]=1;
    if(level[i]<sq)pf[i]=0;
    if(!level[i]%sq)
    pf[i]=root[i];
    else
    pf[i]=pf[root[i]];
    int j,sz=v[i].size();
    for(j=0;j<sz;++j)
    if(!used[v[i][j].e])
    dfs_par(v[i][j].e);
}
void LCA(int x,int y)
{
    int a=x,b=y;
    while(pf[x]!=pf[y])
    {
        if(level[y]>level[x])y=pf[y];
        else
        x=pf[x];
    }
    while(x!=y)
    {
        if(level[y]>level[x])y=root[y];
        else
        x=root[x];
    }
     printf("%d\n",dist[a]+dist[b]-(2*dist[x]));
}
int main()
{
    read();
    dfs_fill(0);
    sq=int(sqrt(double(h)));
    if(sq==0)
    {
        printf("0\n");
        return 0;
    }
    memset(used,0,sizeof(used));
    dfs_par(0);
    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        LCA(x,y);
    }
    return 0;
}
