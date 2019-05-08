#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
#define maxn 205
#define inf 0x3f3f3f
int a[maxn];
int mp[maxn][maxn];
int d[maxn][maxn];
int dis[maxn][maxn][maxn];
int zhi[maxn];
int shu[maxn][maxn];
int n,m;
vector<int>v[maxn];
void bfs(int x)
{
    memset(zhi,0,sizeof(zhi));
    zhi[x]=0;
    queue<int>que;
    que.push(x);
    while(que.size())
    {
        int y=que.front();
        que.pop();
        int len=v[y].size();
        for(int i=0;i<len;i++)
        {
            if (zhi[y]+1<=d[x][v[y][i]]){
                zhi[v[y][i]]=zhi[y]+1;
                dis[x][v[y][i]][zhi[v[y][i]]]=dis[x][v[y][i]][zhi[v[y][i]]]+dis[x][y][zhi[y]]+a[v[y][i]];
                shu[x][v[y][i]]++;
                que.push(v[y][i]);
            }
        }
    }
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
                d[i][j]=d[j][i]=inf;
        }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x][y]=mp[y][x]=1;
        d[x][y]=d[y][x]=1;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
    for(int i=1;i<=n;i++)
    {
        bfs(i);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y][d[x][y]]+a[x]-(shu[x][y]-1)*a[y]<<endl;
    }
    return 0;
}