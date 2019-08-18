#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
struct TT {
    int l, r;
    TT(int _l = 0, int _r = 0) : l(_l), r(_r) {}
} post[MAXN];
struct node {
    int l, r;
    long long lazy, nSum;
} segTree[MAXN << 2];
void pushdown(int i) {
    segTree[i << 1].lazy = segTree[i].lazy;
    segTree[i << 1 | 1].lazy = segTree[i].lazy;
    segTree[i << 1].nSum =
        segTree[i].lazy * (segTree[i << 1].r - segTree[i << 1].l + 1);
    segTree[i << 1 | 1].nSum =
        segTree[i].lazy * (segTree[i << 1 | 1].r - segTree[i << 1 | 1].l + 1);
    segTree[i].lazy = 0;
}
void Build(int i, int l, int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].lazy = 0;
    if (l == r) {
        segTree[i].nSum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    Build(i << 1, l, mid);
    Build(i << 1 | 1, mid + 1, r);
    segTree[i].nSum = segTree[i << 1].nSum + segTree[i << 1 | 1].nSum;
}
void Add(int i, int l, int r, int b) {
    if (r < segTree[i].l || l > segTree[i].r)
        return;
    if (l <= segTree[i].l && r >= segTree[i].r) {
        segTree[i].lazy = b;
        segTree[i].nSum = b * (segTree[i].r - segTree[i].l + 1);
        return;
    }
    if (segTree[i].lazy)
        pushdown(i);
    Add(i << 1, l, r, b);
    Add(i << 1 | 1, l, r, b);
    segTree[i].nSum = segTree[i << 1].nSum + segTree[i << 1 | 1].nSum;
}
long long Query(int i, int l, int r) {
    if (r < segTree[i].l || l > segTree[i].r)
        return 0;
    if (l <= segTree[i].l && r >= segTree[i].r) {
        return segTree[i].nSum;
    }
    if (segTree[i].lazy)
        pushdown(i);
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (r <= mid) {
        return Query(i << 1, l, r);
    } else if (l > mid) {
        return Query(i << 1 | 1, l, r);
    } else
        return Query(i << 1, l, mid) + Query(i << 1 | 1, mid + 1, r);
}
vector<int> dian;
bool vis[MAXN];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        dian.clear();
        int n;
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        memset(segTree, 0, sizeof(segTree));
        memset(post, 0, sizeof(post));
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &post[i].l, &post[i].r);
            dian.push_back(post[i].l);
            dian.push_back(post[i].r);
            dian.push_back(post[i].l + 1);
            dian.push_back(post[i].r + 1);
        }
        sort(dian.begin(), dian.end());
        int len = unique(dian.begin(), dian.end()) - dian.begin();
        Build(1, 1, len + 1);
        for (int i = 0; i < n; i++) {
            post[i].l = lower_bound(dian.begin(), dian.begin() + len, post[i].l) - dian.begin() + 1;
            post[i].r = lower_bound(dian.begin(), dian.begin() + len, post[i].r) - dian.begin() + 1;
            Add(1, post[i].l, post[i].r, i + 1);
        }
        vis[0] = true;
        int ans = 0;
        for (int i = 1; i <= len; i++) {
            long long tt = Query(1, i, i);
            if (!vis[tt]) {
                ans++;
                vis[tt] = true;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}