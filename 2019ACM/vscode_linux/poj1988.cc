#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 3e4+5;
int F[MAXN];
int value[MAXN];
int uu[MAXN];
int find(int x) {
    if(F[x] == -1) return x;
    else {
        int t = F[x];
        F[x] = find(F[x]);
        uu[x] += uu[t];
    }
    return F[x];
}
void bind(int u, int v) {
    int t1 = find(u);
    int t2 = find(v);
    if(t1 != t2) {
        F[t1] = t2;
        uu[t1] += value[t2]+1;
        value[t2] += value[t1]+1;
    }
}
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    memset(F, -1, sizeof(F));
    int p;
    scanf("%d", &p);
    while(p--) {
        getchar();
        char s;
        s = getchar();
        if(s == 'M') {
            int a, b;
            scanf("%d%d", &a, &b);
            bind(b, a);
        } else if(s == 'C') {
            int a;
            scanf("%d", &a);
            printf("%d\n", value[find(a)]-uu[a]);
        }
    }
    return 0;
}