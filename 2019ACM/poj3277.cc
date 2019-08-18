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
const int SIZE = 5e5+4;
struct Node {
    int l, r, w;
    Node():l(0),r(0),w(0){}
    bool operator<(const Node& T) const {
        if(w != T.w) return w < T.w;
        else if(l != T.l) return l < T.l;
        else return r < T.r;
    }
} bd[SIZE];
struct node {
    int l, r;
    long long lazy, nSum;
} segTree[SIZE << 2];
void pushdown(int i) {
    segTree[i << 1].lazy = max(segTree[i].lazy, segTree[i << 1].lazy);
    segTree[i << 1 | 1].lazy = max(segTree[i].lazy, segTree[i << 1 | 1].lazy);
    segTree[i << 1].nSum =
        max(segTree[i].lazy, segTree[i << 1].nSum);
    segTree[i << 1 | 1].nSum =
        max(segTree[i].lazy, segTree[i << 1 | 1].nSum);
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
void Add(int i, int l, int r, LL b) {
    if (r < segTree[i].l || l > segTree[i].r)
        return;
    if (l <= segTree[i].l && r >= segTree[i].r) {
        segTree[i].lazy = b;
        segTree[i].nSum = max(b, segTree[i].nSum);
        return;
    }
    if (segTree[i].lazy)
        pushdown(i);
    Add(i << 1, l, r, b);
    Add(i << 1 | 1, l, r, b);
    segTree[i].nSum = segTree[i << 1].nSum + segTree[i << 1 | 1].nSum;
}
vector<int> arr;
long long Query(int i) {
    int l = segTree[i].l, r = segTree[i].r;
    pushdown(i);
    if(l == r) {
        return (arr[r]-arr[r-1])*segTree[i].nSum;
    }
    return Query(i << 1)+Query(i << 1 | 1);
}
bool cmp(const Node& a, const Node& b) {
    if(a.l != b.l) return a.l < b.l;
    else return a.r < b.r;
}
int main() {
//    freopen("RAW/in", "r", stdin);
//    freopen("RAW/out", "w", stdout);
    int n;
    while(~scanf("%d", &n)) {
        arr.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &bd[i].l, &bd[i].r, &bd[i].w);
            arr.push_back(bd[i].l);
            arr.push_back(bd[i].r);
        }
        sort(arr.begin(), arr.end());
        int len = unique(arr.begin(), arr.end()) - arr.begin();
        for(int i = 0; i < n; i++) {
            bd[i].l = lower_bound(arr.begin(), arr.begin() + len, bd[i].l) - arr.begin() + 1;
            bd[i].r = lower_bound(arr.begin(), arr.begin() + len, bd[i].r) - arr.begin() + 1;
        }
        sort(bd, bd + n);
        // for(int i = 0; i < n; i++) {
        //     printf("%d %d %d\n", bd[i].l, bd[i].r, bd[i].w);
        // }
        Build(1, 1, len + 5);
        for(int i = 0; i < n; i++) {
            Add(1, bd[i].l, bd[i].r - 1, bd[i].w);
            // cout << bd[i].w << endl;
        }
        LL ans = 0;
        ans = Query(1);
        printf("%lld\n", ans);
    }
    return 0;
}
