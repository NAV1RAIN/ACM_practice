#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int BMAX = 1005;
const int DMAX = 2005;
struct plant {
    int x1, x2, h;
    plant() : x1(-1),x2(-1),h(-1) {}
    bool operator < (const plant a) const {
        if(h != a.h) return h > a.h;
        else if(x1 != a.x1) return x1 < a.x1;
        else return x2 < a.x2;
    }
} pp[BMAX];
const int INF = 0x3f3f3f3f;
struct qnode {
    int v, c;
    qnode(int _v = 0, int _c = 0) : v(_v), c(_c) {}
    bool operator < (const qnode &r) const {
        return c > r.c;
    }
};
struct Edge {
    int v, cost;
    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[DMAX];
bool vis[DMAX];
int dist[DMAX];
void Dijkstra(int n, int start) {
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }
    priority_queue<qnode> que;
    while(!que.empty()) que.pop();
    dist[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while(!que.empty()) {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < E[u].size(); i++) {
            int v = E[tmp.v][i].v;
            int cost = E[u][i].cost;
            if(!vis[v] && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                que.push(qnode(v, dist[v]));
            }
        }
    }
}
void addedge(int u, int v, int w) {
    E[u].push_back(Edge(v, w));
}
void init() {
    for(int i = 0; i < DMAX; i++) {
        E[i].clear();
    }
    memset(pp, 0, sizeof(pp));
}
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        int tot = 1;
        int n, x, y, MAX;
        scanf("%d%d%d%d", &n, &x, &y, &MAX);
        pp[0].x1 = pp[0].x2 = x, pp[0].h = y;
        for(int i = 1; i <= n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(pp[0].h >= c) {
                pp[tot].x1 = a, pp[tot].x2 = b, pp[tot].h = c;
                tot++;
            }
        }
//        printf("%d\n", tot);
        sort(pp+1, pp + tot);
        for(int i = 0; i <= tot; i++) {
            bool l, r;
            l = r = false;
            for(int j = i+1; j <= tot && pp[i].h - pp[j].h <= MAX; j++) {
                if(!l && pp[i].x1 >= pp[j].x1 && pp[i].x1 <= pp[j].x2) {
                    int tt1 = pp[i].x1-pp[j].x1;
                    int tt2 = pp[j].x2-pp[i].x1;
                    addedge(i << 1, j << 1, pp[i].x1-pp[j].x1);
                    addedge(i << 1, j << 1 ^ 1, pp[j].x2-pp[i].x1);
                    l = true;
                }
                if(!r && pp[i].x2 >= pp[j].x1 && pp[i].x2 <= pp[j].x2) {
                    int tt1 = pp[i].x2-pp[j].x1;
                    int tt2 = pp[j].x2-pp[i].x2;
                    addedge(i << 1 ^ 1, j << 1, pp[i].x2-pp[j].x1);
                    addedge(i << 1 ^ 1, j << 1 ^ 1, pp[j].x2-pp[i].x2);
                    r = true;
                }
            }
            if(!l && pp[i].h <= MAX) addedge(i << 1, (tot+1)<<1, 0);
            if(!r && pp[i].h <= MAX) addedge(i << 1 ^ 1, (tot+1)<<1, 0);
        } //共有(tot+1)*2个点，起点为1
        Dijkstra((tot+1)<<1, 1);
        printf("%d\n", dist[(tot+1)<<1]+y);
    }
    return 0;
}
