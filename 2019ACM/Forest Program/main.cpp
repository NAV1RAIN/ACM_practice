#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 998244353;
const int SIZE = 3e5 + 5;
LL sum, ans;
int vis[SIZE], path[SIZE];
vector<LL> G[SIZE];
void init() {
    sum = 0, ans = 1;
    for(int i = 0; i < SIZE; i++) G[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));
}
LL quickPow(LL a, LL b) {
    LL hh = 1;
    while(a) {
        if(a & 1) hh = (hh*b)%MOD;
        b = (b*b)%MOD;
        a >>= 1;
    }
    return hh % MOD;
}
void DFS(int pre, int now) {
    vis[now] = 1;
    int len = G[now].size();
    for(int i = 0; i < len; i++) {
        int to = G[now][i];
        if(to == pre) continue;
        if(vis[to] == 0) {
            path[to] = now;
            DFS(now, to);
        } else if(vis[to] == 1) {
            int temp = now;
            int cnt = 1;
            while(temp != to) {
                cnt++;
                temp = path[temp];
            }
            sum += cnt;
            ans = (ans * (quickPow(cnt, 2) - 1)) % MOD;
        } else {
            continue;
        }
    }
    vis[now] = 2;
}
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        init();
        int u, v;
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) DFS(0, i);
        }
        printf("%lld\n", quickPow(m - sum, 2) * ans % MOD);
    }
    return 0;
}