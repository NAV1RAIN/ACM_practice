#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int Max[MAXN][MAXN];
bool used[MAXN][MAXN];
int cost[MAXN][MAXN];
int minc = INF;
int Prim(int n) {
    int ans = 0;
    memset(vis, false, sizeof(vis));
    memset(Max, 0, sizeof(Max));
    memset(used, false, sizeof(used));
    vis[0] = true;
    pre[0] = -1;
    for(int i = 1; i < n; i++) {
        lowc[i] = cost[0][i];
        pre[i] = 0;
    }
    lowc[0] = 0;
    for(int i = 1; i < n; i++) {
        int minc = INF;
        int p = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && minc > lowc[j]) {
                minc = lowc[j];
                p = j;
            }
        }
        if(minc == INF) return -1;
        ans += minc;
        vis[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        for(int j = 0; j < n; j++) {
            if(vis[j] && j != p) Max[j][p] = Max[p][j] = max(Max[j][pre[p]], lowc[p]);
            if(!vis[j] && lowc[j] > cost[p][j]) {
                lowc[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    int t;
    cin >> t;
    while(t--) {
        memset(cost, INF, sizeof(cost));
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            cost[a-1][b-1] = cost[b-1][a-1] = c;
        }
        int cx = Prim(n);
        if(cx == minc) printf("Not Unique!");
        else printf("%d\n", minc);
    }
    return 0;
}
