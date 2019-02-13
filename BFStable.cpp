#include<iostream>
#include<queue>
using namespace std;
int a[1024][1024],n;
struct cell
{
    int x,y;
};
cell dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
void bfs(cell c)
{
    int i;
    cell c1,c2;
    queue<cell>q;
    a[c.x][c.y]=2;
    q.push(c);
    while(!q.empty())
    {
        c1=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            c2.x=c1.x+dir[i].x;
            c2.y=c2.y+dir[i].y;
            if(!a[c2.x][c2.y])
            {
                a[c2.x][c2.y]=a[c1.x][c1.y]+1;
                q.push(c2);
            }
        }
    }
}
void read()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cin>>a[i][j];
    for(i=0;i<=n+1;i++)
    a[0][i]=a[i][0]=a[n+1][i]=a[i][n+1]=1;
}
int main()
{
    cell f;
    f.x=f.y=1;
    read();
    bfs(f);
    cout<<a[n][n]-2;
    return 0;
}
/*
9
0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0
0 1 0 0 1 1 0 0 0
0 1 0 0 1 0 0 1 1
0 0 0 0 0 0 0 1 1
0 0 0 1 0 0 0 0 0
0 0 1 1 0 0 1 0 0
0 0 0 1 0 0 1 1 0
0 1 1 1 0 0 0 0 0


16
*/
    
                