#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int sgn(double n) {
    if(n < eps) return 0;
    else return n > 0 ? 1 : -1;
}
const int MAXN = 505;
const int MAXM = MAXN*MAXN;
struct Point {
    double x, y;
    double getdis(const Point p) {
        return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    }
} point[MAXN];
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
    int n;
    while(~scanf("%d", &n)) {
        init();
        for(int i = 0; i < 2*n; i+=2) {
            scanf("%lf%lf%lf%lf", &point[i].x, &point[i].y, &point[i^1].x, &point[i^1].y);
        }
        double l = 0, r = 40000;
        while(fabs(l-r) > eps) {
            init();
            double mid = (l+r)/2;
            for(int i = 0; i < n*2; i += 2) {
                for(int j = i+2; j < n*2; j += 2) {
                    // double l1 = point[i].getdis(point[j]);
                    // double l2 = point[i^1].getdis(point[j]);
                    // double l3 = point[i].getdis(point[j^1]);
                    // double l4 = point[i^1].getdis(point[j^1]);
                    if(point[i].getdis(point[j]) < mid) {
                        addedge(i, j^1);
                        addedge(j, i^1);
                    }
                    if(point[i^1].getdis(point[j]) < mid) {
                        addedge(i^1, j^1);
                        addedge(j, i);
                    }
                    if(point[i].getdis(point[j^1]) < mid) {
                        addedge(i, j);
                        addedge(j^1, i^1);
                    }
                    if(point[i^1].getdis(point[j^1]) < mid) {
                        addedge(i^1, j);
                        addedge(j^1, i);
                    }
                }
            }
            if(TwoSat(2*n)) l = mid;
            else r = mid;
        }
        printf("%.2f\n", l/2);
    }
    return 0;
}