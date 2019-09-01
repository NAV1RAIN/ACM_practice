#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1010;
const long long INF = 0x3f3f3f3f3f3f3f3f;
bool vis[MAXN];
long long pre[MAXN];  //路径前向星数组
long long cost[MAXN][MAXN];  //图
long long lowcost[MAXN];  //起点到各点的最短路的值
void Dij(int n, int beg) {
    for(long long i = 0; i < n; i++) {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for(int i = 0; i < n; i++) {
        int k = -1;
        long long Min = INF;
        for(long long j = 0; j < n; j++) {
            if(!vis[j] && lowcost[j] < Min) {
                Min = lowcost[j];
                k = j;
            }
        }
        if(k == -1)
            break;
        vis[k] = true;
        for(long long j = 0; j < n; j++) {
            if(!vis[j] && lowcost[k] + cost[k][j] < lowcost[j]) {
                lowcost[j] = lowcost[k] + cost[k][j];
                pre[j] = k;
            }
        }
    }
}

int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        long long n, m;
        scanf("%lld%lld", &n, &m);
        for(int i = 0; i < m; i++) {
            int a, b;
            long long c;
            scanf("%d%d%lld", &a, &b, &c);
            cost[a][b] = c;
            // printf("%d %d\n", a, b);
            // printf("%lld\n", cost[a][b]);
        }
        for(int i = 0; i < 6; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d %d\n", a, b);
            Dij(n, b);
            long long hh = -lowcost[a];
            printf("%lld\n", hh);
            cost[b][a] += hh;
        }
    }
    return 0;
}