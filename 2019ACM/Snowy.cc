#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> P;
const long long MAXN = 5010;     //点数的最大值
const long long MAXM = 1200010;  //边数的最大值
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
    long long to, next, cap, flow;
} edge[MAXM];  //注意是 MAXM
long long tol;
long long head[MAXN];
void init() {
    tol = 2;
    memset(head, -1, sizeof(head));
}
void addedge(long long u, long long v, long long w, long long rw = 0) {
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
long long Q[MAXN];
long long dep[MAXN], cur[MAXN], sta[MAXN];
bool bfs(long long s, long long t, long long n) {
    long long front = 0, tail = 0;
    memset(dep, -1, sizeof(dep[0]) * (n + 1));
    dep[s] = 0;
    Q[tail++] = s;
    while (front < tail) {
        long long u = Q[front++];
        for (long long i = head[u]; i != -1; i = edge[i].next) {
            long long v = edge[i].to;
            if (edge[i].cap > edge[i].flow && dep[v] == -1) {
                dep[v] = dep[u] + 1;
                if (v == t) return true;
                Q[tail++] = v;
            }
        }
    }
    return false;
}
long long dinic(long long s, long long t, long long n) {
    long long maxflow = 0;
    while (bfs(s, t, n)) {
        for (long long i = 0; i < n; i++) cur[i] = head[i];
        long long u = s, tail = 0;
        while (cur[s] != -1) {
            if (u == t) {
                long long tp = INF;
                for (long long i = tail - 1; i >= 0; i--) tp = min(tp, edge[sta[i]].cap - edge[sta[i]].flow);
                maxflow += tp;
                for (long long i = tail - 1; i >= 0; i--) {
                    edge[sta[i]].flow += tp;
                    edge[sta[i] ^ 1].flow -= tp;
                    if (edge[sta[i]].cap - edge[sta[i]].flow == 0) tail = i;
                }
                u = edge[sta[tail] ^ 1].to;
            } else if (cur[u] != -1 && edge[cur[u]].cap > edge[cur[u]].flow && dep[u] + 1 == dep[edge[cur[u]].to]) {
                sta[tail++] = cur[u];
                u = edge[cur[u]].to;
            } else {
                while (u != s && cur[u] == -1) u = edge[sta[--tail] ^ 1].to;
                cur[u] = edge[cur[u]].next;
            }
        }
    }
    return maxflow;
}
struct Node {
    long long r, c, w;
} dian[MAXN];
bool cmp1(const P& a, const P& b) {
    return a.first < b.first;
}
bool cmp2(const Node& a, const Node& b) {
    return a.r < b.r;
}
bool cmp3(const Node& a, const Node& b) {
    return a.c < b.c;
}
P r[MAXN], c[MAXN];
long long R[MAXN], C[MAXN];
long long tor, toc;
set<long long> rNum, cNum;
void Init() {
    init();
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(R, 0, sizeof(R));
    memset(C, 0, sizeof(C));
    memset(dian, 0, sizeof(dian));
    tor = toc = 0;
    rNum.clear();
    cNum.clear();
}
int main() {  //(rr+cc)*2+n+2
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    long long T;
    scanf("%lld", &T);
    while(T--) {
        Init();
        long long maxx = -INF;
        long long n;
        scanf("%lld", &n);
        long long x, y, w;
        for(long long i = 0; i < n; i++) {
            scanf("%lld%lld%lld",&x, &y, &w);
            maxx = max(maxx, w);
            dian[i].r = x, dian[i].c = y, dian[i].w = w;
            r[i].first = x, r[i].second = w;
            c[i].first = y, c[i].second = w;
            rNum.insert(x), cNum.insert(y);
        }
        if(maxx <= 0) {
            printf("0\n");
            continue;
        }
        sort(r, r + n, cmp1);
        sort(c, c + n, cmp1);
        long long rN = 0, cN = 0;
        R[rN] += r[0].second;
        sort(dian, dian+n, cmp2);
        dian[0].r = 0;
        for(int i = 1; i < n; i++) {
            if(r[i].first != r[i-1].first) {
                rN++;
            }
            R[rN] += r[i].second;
            dian[i].r = rN;
        }
        C[cN] += c[0].second;
        sort(dian, dian + n, cmp3);
        dian[0].c = 0;
        for(int i = 1; i < n; i++) {
            if(c[i].first != c[i-1].first) {
                cN++;
            }
            C[cN] += c[i].second;
            dian[i].c = cN;
        }
        long long rr = rNum.size(), cc = cNum.size();
        int S = n+(rr+cc)*2+1, E = n+(rr+cc)*2+2;
        for(int i = 0; i < rr; i++) {
            addedge(S, i<<1^1, INF);
            addedge(i<<1^1, i<<1, R[i]);
        }
        for(int i = 0; i < cc; i++) {
            addedge((rr+i)<<1, (rr+i)<<1^1, C[i]);
            addedge((rr+i)<<1^1, E, INF);
        }
        for(int i = 0; i < n; i++) {
            // printf("%d\n", dian[i].w);
            addedge(dian[i].r<<1, (rr+cc)*2+i, dian[i].w);
            addedge((rr+cc)*2+i, (rr+dian[i].c)<<1, dian[i].w);
        }
        long long ans = dinic(S, E, (rr+cc)*2+n+2);
        printf("%lld\n", ans);
    }
    return 0;
}