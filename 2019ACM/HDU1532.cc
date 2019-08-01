#include <bits/stdc++.h>
using namespace std;

/** SAP 算法（矩阵形式）* 结点编号从 0 开始*/
const long long MAXN = 1100;
long long maze[MAXN][MAXN];
long long gap[MAXN], dis[MAXN], pre[MAXN], cur[MAXN];
long long sap(long long start, long long end, long long nodenum) {
    memset(cur, 0, sizeof(cur));
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    long long u = pre[start] = start, maxflow = 0, aug = -1;
    gap[0] = nodenum;
    while (dis[start] < nodenum) {
    loop:
        for (long long v = cur[u]; v < nodenum; v++)
            if (maze[u][v] && dis[u] == dis[v] + 1) {
                if (aug == -1 || aug > maze[u][v]) aug = maze[u][v];
                pre[v] = u;
                u = cur[u] = v;
                if (v == end) {
                    maxflow += aug;
                    for (u = pre[u]; v != start; v = u, u = pre[u]) {
                        maze[u][v] -= aug;
                        maze[v][u] += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        long long mindis = nodenum - 1;
        for (long long v = 0; v < nodenum; v++)
            if (maze[u][v] && mindis > dis[v]) {
                cur[u] = v;
                mindis = dis[v];
            }
        if ((--gap[dis[u]]) == 0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return maxflow;
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    long long n, m;
    while(~scanf("%lld%lld", &n, &m)) {
        memset(maze, 0, sizeof(maze));
        for(long long i = 0; i < n; i++) {
            long long s, e, c;
            scanf("%lld%lld%lld", &s, &e, &c);
            s--, e--;
            maze[s][e] += c;
        }
        printf("%lld\n", sap(0, m-1, m));
    }
    return 0;
}