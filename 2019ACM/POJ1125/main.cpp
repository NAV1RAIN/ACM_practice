#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];  //路径前向星数组
int cost[MAXN][MAXN];  //图
int lowcost[MAXN];  //起点到各点的最短路的值
void Dijkstra(int n, int beg) {  //n为点的数目，beg为起点
//    int ans = INF;
    for(int i = 0; i <= n; i++) {
        lowcost[i] = -1;
        vis[i] = false;
        pre[i] = -1;
    }
    for(int i = 1; i <= n; i++) {
        lowcost[i] = cost[1][i];
    }
    for(int i = 1; i <= n; i++) {
        int k = -1;
        int MAX = 0;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]) {
                k = j;
                break;
            }
        }
        if(k == -1) break;
        vis[k] = true;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && min(cost[k][j], lowcost[k]) > lowcost[j]) {
                lowcost[j] = min(lowcost[k], cost[k][j]);
                pre[j] = k;
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        memset(cost, INF, sizeof(cost));
        printf("Scenario #%d:\n", i);
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            cost[a][b] = cost[b][a] = c;
        }
        Dijkstra(n, 1);
//        int ans = INF;
//        for(int i = 1; i <= n; i++) {
//            printf("%d\n", lowcost[i]);
//            ans = min(ans, lowcost[i]);
//        }
        printf("%d\n\n", lowcost[n]);
    }
    return 0;
}
