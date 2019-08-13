#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2010;
struct TT {
    ll sum, maxsum, lmax, rmax;
} tree[MAXN << 2];
int idList[MAXN];
void update(int id) {
    int ls = id << 1, rs = id << 1 | 1;
    tree[id].sum = tree[ls].sum + tree[rs].sum;
    tree[id].maxsum = max(max(tree[ls].maxsum, tree[rs].maxsum), tree[ls].rmax + tree[rs].lmax);
    tree[id].lmax = max(tree[ls].lmax, tree[ls].sum + tree[rs].lmax);
    tree[id].rmax = max(tree[rs].rmax, tree[rs].sum + tree[ls].rmax);
}
void build(int id, int l, int r) {
    tree[id].sum = tree[id].lmax = tree[id].rmax = tree[id].maxsum = 0;
    if(l == r) {
        idList[l] = id;
        return ;
    }
    int mid = (l + r) >> 1;
    int ls = id << 1, rs = id << 1 | 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    update(id);
}
struct Node {
    int r, c, w;
} dian[MAXN];
int r[MAXN];
bool cmp(const Node& a, const Node& b) { return a.c != b.c ? a.c < b.c : a.r < b.r; }
void Init() {
    memset(tree, 0, sizeof(tree));
    memset(idList, 0, sizeof(idList));
    memset(dian, 0, sizeof(dian));
    memset(r, 0, sizeof(r));
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    for(scanf("%d", &T); T--; ) {
        Init();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &dian[i].c, &dian[i].r, &dian[i].w);
            r[i] = dian[i].r;
        }
        sort(r, r + n);
        int rN = 0;
        for(int i = 1; i <= n; i++) if(r[i] != r[i-1] || i == n) r[rN++] = r[i-1];
        for(int i = 0; i < n; i++) dian[i].r = lower_bound(r, r + rN, dian[i].r) - r + 1;
        int k = 0;
        long long ans = 0;
        sort(dian, dian + n, cmp);
        for(int i = 0; i < n; i++) {
            if(i == 0 || dian[i].c != dian[i-1].c) {
                build(1, 1, rN);
                for(int j = i; j < n; j = k) {
                    for(k = j; k < n && dian[j].c == dian[k].c; k++) {
                        int xx = idList[dian[k].r];
                        // printf("%d\n", dian[k].r);
                        tree[xx].sum += dian[k].w;
                        tree[xx].maxsum = tree[xx].lmax = tree[xx].rmax = (tree[xx].sum >= 0 ? tree[xx].sum : 0);
                        for(xx >>= 1; xx; xx >>= 1) {
                            update(xx);
                        }
                    }
                    if(ans < tree[1].maxsum) ans = tree[1].maxsum;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}