#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, m, deg[maxn], rt, a[maxn], dep[maxn], val[maxn];
int f[maxn][20];
vector<int> E[maxn], G[maxn], T[maxn];
void BFS() {
    queue<int> q;
    rt = n + 1;
    for (int i = 1; i <= n; i++)
        if (!deg[i]) {
            q.push(i);
            E[rt].push_back(i);
            G[i].push_back(rt);
        }
    int tot = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        a[++tot] = u;
        for (vector<int>::iterator it = E[u].begin(); it != E[u].end(); it++)
            if ((--deg[(*it)]) == 0) q.push((*it));
    }
}
int LCA(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--)
        if (dep[y] > dep[x] && dep[f[y][i]] >= dep[x]) y = f[y][i];
    for (int i = 19; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return x == y ? x : f[x][0];
}
void Init() {
    for (int i = 1; i <= n + 1; i++) {
        E[i].clear();
        G[i].clear();
        T[i].clear();
        dep[i] = deg[i] = 0;
    }
}
void addEdge(int u, int v) {
    E[u].push_back(v);
    G[v].push_back(u);
    deg[v]++;
}
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d%d", &n, &m);
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(v, u);
        }
        BFS();
        dep[rt] = 1;
        for (int i = 1; i <= n; i++) {
            int u = a[i], fa = -1;
            for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++)
                fa = (fa == -1 ? (*it) : LCA(fa, (*it)));
            dep[u] = dep[fa] + 1;
            f[u][0] = fa;
            T[fa].push_back(u);
            for (int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int u, v;
            scanf("%d%d", &u, &v);
            int lca = LCA(u, v);
            printf("%d\n", dep[u] + dep[v] - dep[lca] - 1);
        }
    }

    return 0;
}
