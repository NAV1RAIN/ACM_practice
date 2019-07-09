#include <bits/stdc++.h>
using namespace std;
const int maxn=5050;
int n,m,s;
int cnt;
vector<int>vg[maxn];
vector<int>g[maxn];
bool used[maxn];
bool good[maxn];
int head;

void dfs1(int x){
    good[x]=true;
    for(int i=0;i<g[x].size();i++){
        if(!good[g[x][i]]) dfs1(g[x][i]);
    }
}

void dfs2(int x){
    used[x]=true;
    int sz1=vg[x].size();
    for(int i=0;i<sz1;i++){
        if(!good[vg[x][i]]&&!used[vg[x][i]]) head=vg[x][i],dfs2(vg[x][i]);
    }
    int sz2=g[x].size();
    for(int i=0;i<sz2;i++){
        if(!good[g[x][i]]) dfs1(g[x][i]);
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    s--;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        g[u].push_back(v);
        vg[v].push_back(u);
    }
    dfs1(s);
    for(int i=0;i<n;i++){
        if(!good[i]){
            dfs2(i);
            cnt++;
            dfs1(head);
        }
    }
    printf("%d\n",cnt);
}

