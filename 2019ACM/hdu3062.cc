#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2020;
const int MAXM = MAXN*MAXN;
struct Edge {
    int to, next;
} edge[MAXM];
int head[MAXM], tot;
void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
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
bool TwoSat(int n) {
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    memset(num, 0, sizeof(num));
    Index = scc = top = 0;
    for(int i = 0; i < n; i++) {
        if(!DFN[i]) Tarjan(i);
    }
    for(int i = 0; i < n; i += 2) {
        if(Belong[i] == Belong[i^1]) return false;
    }
    return true;
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i = 0; i < m; i++) {
            int a1, a2, c1, c2;
            scanf("%d%d%d%d", &a1, &a2, &c1, &c2);
            addedge(a1<<1^c1, a2<<1^c2^1);
            addedge(a2<<1^c2, a1<<1^c1^1);
        }
        if(TwoSat(2*n)) {
            printf("YES\n");
        } else printf("NO\n");
        // printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}