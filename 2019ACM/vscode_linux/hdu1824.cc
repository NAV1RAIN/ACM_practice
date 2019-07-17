#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6005;
const int MAXM = MAXN*MAXN;
struct Edge {
    int to, next;
} edge[MAXM];
int head[MAXN], tot;
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
    int T, M;
    while(~scanf("%d%d", &T, &M)) {
        init();
        for(int i = 0; i < T; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            addedge(a<<1^1, b<<1);
            addedge(a<<1^1, c<<1);
            addedge(b<<1^1, a<<1);
            addedge(c<<1^1, a<<1);
        }
        for(int i = 0; i < M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            addedge(a<<1, b<<1^1);
            addedge(b<<1, a<<1^1);
        }
        if(TwoSat(6*T)) {
            printf("yes\n");
        } else printf("no\n");
    }
    return 0;
}