#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int SIZE = 1e4+5;
struct Node {
    int l, r;
    Node():l(0),r(0){}
} task[SIZE];
bool cmp(const Node& a, const Node& b) {
    if(a.r != b.r) return a.r < b.r;
    else return a.l > b.l;
}
Node tt[SIZE];
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(task, 0, sizeof(task));
        memset(tt, 0, sizeof(tt));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &task[i].l, &task[i].r);
        }
        sort(task, task + n, cmp);
        int tol = 0;
        int jjj = -1;
        for(int i = 0; i < n; i++) {
            if(jjj != task[i].r) {
                jjj = task[i].r;
                tt[tol].l = task[i].l;
                tt[tol].r = task[i].r;
                tol++;
            }
        }
        int ans = 0;
        int jl = tt[0].r;
        for(int i = 1; i < tol; i++) {
            if(tt[i].l > jl) {
                ans += (tt[i].l-jl)/2;
                if((tt[i].l-jl)%2) ans++;
                jl = tt[i].l;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
