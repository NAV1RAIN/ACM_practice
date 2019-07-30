#include <bits/stdc++.h>
using namespace std;
typedef pair<int,double> p;
const int MAXN = 1005;
const int MAXM = 2e6+5;
int F[MAXN];
struct Edge {
    int u, v;
    double w;
} edge[MAXM];
Edge edge2[MAXM];
p vec[MAXN][MAXN];
int vis[MAXM];
int tol, tol2;
inline void addedge(int u, int v, double w) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}
inline void addedge2(int u, int v, double w) {
    edge2[tol2].u = u;
    edge2[tol2].v = v;
    edge2[tol2++].w = w;
}
bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}
bool cmp2(const p& a, const p& b) {
    return a.second < b.second;
}
int find(int x) {
    if(F[x] == -1) return x;
    else return F[x] = find(F[x]);
}
double Kruskal(int n) {
    memset(F, -1, sizeof(F));
    int cnt = 0;
    double ans = 0;
    sort(edge, edge+tol, cmp);
    for(int i = 0; i < tol; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        double w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2) {
            addedge2(u, v, w);
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    if(cnt < n-1) return -1;
    return ans;
}
int x[MAXN], y[MAXN];
inline double distance(int x1, int y1, int x2, int y2) {
    return sqrt(((double)x1-x2)*(x1-x2)+((double)y1-y2)*(y1-y2));
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    int n, k;
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < MAXN; i++) {
            for(int j = i; j < MAXN; j++) {
                vec[i][j].first = vec[i][j].second = 1000000000;
                vec[j][i].first = vec[j][i].second = 1000000000;
            }
        }
        tol = tol2 = 0;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                // if(i == j) continue;
                double dis = distance(x[i], y[i], x[j], y[j]);
                addedge(i, j, dis);
                addedge(j, i, dis);
                vec[i][j].second = vec[j][i].second = dis;
                vec[i][j].first = j;
                vec[j][i].first = i;
            }
        }
        // for(int i = 0; i < n; i++) {
        //     sort((&vec[i][0]), (&vec[i][0])+n, cmp2);
        // }
        double temp, ans;
        ans = temp = Kruskal(n);
        for(int i = 0; i < tol2; i++) {
            int uu = edge2[i].u, vv = edge2[i].v;
            if(uu == 0 || vv == 0) continue;
            for(int j = 0; j < n; j++) {
                if(vec[uu][j].first != vv) {
                    ans = max(ans, temp-edge2[i].w+vec[uu][j].second);
                    break;
                }
            }
            for(int j = 0; j < n; j++) {
                if(vec[vv][j].first != uu) {
                    ans = max(ans, temp-edge2[i].w+vec[vv][j].second);
                    break;
                }
            }
        }
        printf("%.2f\n", ans*k);
    }
    return 0;
}