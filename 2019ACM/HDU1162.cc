#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;    //最大点数
const int MAXM = 20000;  //最大边数
int F[MAXN];             //并查集使用
struct Edge {
    int u, v;
    double w;
} edge[MAXM];  //存储边的信息，包括起点/终点/权值
int tol;       //边数，加边前赋值为 0
void addedge(int u, int v, double w) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}  //排序函数，讲边按照权值从小到大排序
bool cmp(Edge a, Edge b) { return a.w < b.w; }
int find(int x) {
    if (F[x] == -1)
        return x;
    else
        return F[x] = find(F[x]);
}  //传入点数，返回最小生成树的权值，如果不连通返回 -1
double Kruskal(int n) {
    memset(F, -1, sizeof(F));
    sort(edge, edge + tol, cmp);
    int cnt = 0;  //计算加入的边数
    double ans = 0;
    for (int i = 0; i < tol; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        double w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if (t1 != t2) {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    if (cnt < n - 1)
        return 1;  //不连通
    else
        return ans;
}
double x[MAXN], y[MAXN];
double getdis(double a1, double b1, double a2, double b2) {
    return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n;
    while (~scanf("%d", &n)) {
        tol = 0;
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dis = getdis(x[i], y[i], x[j], y[j]);
                addedge(i, j, dis);
                addedge(j, i, dis);
            }
        }
        printf("%.2f\n", Kruskal(n));
    }
    return 0;
}