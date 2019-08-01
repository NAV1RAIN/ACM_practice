#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 205;
const int INF = 0x3f3f3f3f;
double x[MAXN], y[MAXN];
double cost[MAXN][MAXN];
double lowcost[MAXN];
bool vis[MAXN];
int pre[MAXN];
double Max = -1;
void Dijkstra(int n, int beg) {
    for(int i = 1; i <= n; i++) {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for(int j = 1; j <= n; j++) {
        int k = -1;
        double Min = INF;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && lowcost[i] < Min) {
                Min = lowcost[i];
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = true;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && max(lowcost[k], cost[i][k]) < lowcost[i]) {
                lowcost[i] = max(lowcost[k], cost[i][k]);
                pre[i] = k;
            }
        }
    }
}

int main()
{
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int n;
    int time = 1;
    while(scanf("%d", &n) != EOF) {
        if(n == 0) break;
        Max = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cost[i][j] = INF;
            }
        }
        for(int i = 1; i <= n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                double temp = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                cost[i][j] = cost[j][i] = temp;
            }
        }
        Dijkstra(n, 1);
        printf("Scenario #%d\n", time++);
        printf("Frog Distance = %.3f\n\n", lowcost[2]);
    }
    return 0;
}
