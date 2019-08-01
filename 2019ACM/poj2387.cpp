#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];
int lowcost[MAXN];
int cost[MAXN][MAXN];
void Dijsktra(int n, int beg) {
    for(int i = 1; i <= n; i++) {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for(int j = 1; j <= n; j++) {
        int k = -1;
        int Min = INF;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && lowcost[i] < Min) {
                Min = lowcost[i];
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = true;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && lowcost[k]+cost[k][i] < lowcost[i]) {
                lowcost[i] = lowcost[k]+cost[k][i];
                pre[i] = k;
            }
        }
    }
}
int main()
{
    int t, n;
    scanf("%d%d", &t, &n);
    memset(cost, INF, sizeof(cost));
    for(int i = 0; i < t; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(cost[a][b] > c) cost[a][b] = cost[b][a] = c;
    }
    Dijsktra(n, 1);
    printf("%d\n", lowcost[n]);
    return 0;
}
