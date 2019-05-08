#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const int MAXM = 10000;
int F[MAXN];
struct Edge{
    int u, v, w;
}edge[MAXM];
int tol;
void addedge(int u, int v, int w) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
int find(int x) {
    if(F[x] == -1) return x;
    else return F[x] = find(F[x]);
}
int Kruskal(int n) {
    memset(F, -1, sizeof(F));
    sort(edge, edge+tol, cmp);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < tol; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2) {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    if(cnt < n-1) return -1;
    else return ans;
}
int dis[MAXN][MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &dis[i][j]);
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        dis[a][b] = dis[b][a] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) {
                addedge(i, j, dis[i][j]);
            }
        }
    }
//    printf("%d\n", tol);
    int ans = Kruskal(n);
    printf("%d\n", ans);
    return 0;
}