#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30005;
// const int MAXM = 2*MAXN;
struct Edge {
    int to, next;
    Edge(int x, int y):to(x),next(y){}
};
vector<Edge> edge;
int head[MAXN], tot;
void init() {
    tot = 0;
    edge.clear();
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v) {
    edge.push_back(Edge(v, head[u]));
    // edge[tot].to = v;
    // edge[tot].next = head[u];
    head[u] = tot++;
}
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
int Index, top;
int scc;
bool Instack[MAXN];
int num[MAXN];
void Tarjan(int u) {
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if(!DFN[v]) {
            Tarjan(v);
            if(Low[u] > Low[v]) Low[u] = Low[v];
        } else if(Instack[v] && Low[u] > DFN[v]) {
            Low[u] = DFN[v];
        }
    }
    if(Low[u] == DFN[u]) {
        scc++;
        do {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        } while(v != u);
    }
}
int a[MAXN], b[MAXN], c[MAXN];
bool TwoSat(int n) {
    init();
    for(int i = 0; i < n; i++) {
        if(c[i] == 0) {
            addedge(a[i]<<1^1, b[i]<<1);
            addedge(b[i]<<1^1, a[i]<<1);
        } else if(c[i] == 1) {
            addedge(a[i]<<1, b[i]<<1);
            addedge(b[i]<<1, a[i]<<1);
            addedge(a[i]<<1^1, b[i]<<1^1);
            addedge(b[i]<<1^1, a[i]<<1^1);
        } else if(c[i] == 2) {
            addedge(a[i]<<1, b[i]<<1^1);
            addedge(b[i]<<1, a[i]<<1^1);
        }
    }
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    memset(num, 0, sizeof(num));
    Index = scc = top = 0;
    for(int i = 0; i < n*2; i++) {
        if(!DFN[i]) Tarjan(i);
    }
    for(int i = 0; i < n*2; i += 2) {
        if(Belong[i] == Belong[i^1]) return false;
    }
    return true;
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        int l = 0, r = m;
        int ans = -1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(TwoSat(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}