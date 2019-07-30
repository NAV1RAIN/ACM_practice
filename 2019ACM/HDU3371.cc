#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1100;  //最大点数
const int MAXM = 500005;  //最大边数
int F[MAXN];  //并查集使用
struct Edge {
    int u, v, w;
} edge[MAXM];  //存储边的信息，包括起点/终点/权值
int tol;  //边数，加边前赋值为0
void addedge(int u, int v, int w) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}
//排序函数，讲边按照权值从小到大排序
bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}
int Find(int x) {
    if(F[x] == -1)
        return x;
    return F[x] = Find(F[x]);
}
int cnt = 0;  //计算加入的边数
//传入点数，返回最小生成树的权值，如果不连通返回-1
int Kruskal(int n) {
    sort(edge, edge+tol, cmp);
    int ans = 0;
    for(int i = 0; i < tol; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = Find(u);
        int t2 = Find(v);
        if(t1 != t2) {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if(cnt == n-1)
            break;
    }
    if(cnt < n-1)
        return -1;
    return ans;
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        tol = 0;
        cnt = 0;
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        memset(F, -1, sizeof(F));
        int t1, t2;
        for(int i = 0; i < k; i++) {
            int num;
            scanf("%d", &num);
            for(int j = 0; j < num; j++) {
                int tt;
                scanf("%d", &tt);
                if(j == 0)
                    t1 = Find(tt);
                else {
                    t2 = Find(tt);
                    if(t1 != t2) {
                        F[t2] = t1;
                        cnt++;
                    }
                }
            }
        }
        if(cnt == n-1) printf("0\n");
        else printf("%d\n", Kruskal(n));
    }
    return 0;
}