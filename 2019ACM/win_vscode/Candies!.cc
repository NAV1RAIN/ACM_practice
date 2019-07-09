#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 100005;
struct Node {
    int l, r;
    int nSum;
} segTree[MAXN * 3 - 1];
int num[MAXN];
void Build(int i, int l, int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    if (l == r) {
        segTree[i].nSum = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(i << 1, l, mid);
    Build(i << 1 | 1, mid + 1, r);
    segTree[i].nSum = (segTree[i << 1].nSum + segTree[i << 1 | 1].nSum);
}
void Add(int i, int t, int b)
{
    segTree[i].nSum += b;
    if (segTree[i].l == t && segTree[i].r == t)
        return;
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (t <= mid)
        Add(i << 1, t, b);
    else
        Add(i << 1 | 1, t, b);
}
int Query(int i, int l, int r)
{
    if (l == segTree[i].l && r == segTree[i].r) {
        return segTree[i].nSum;
    }
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (r <= mid)
        return Query(i << 1, l, r);
    else if (l > mid)
        return Query(i << 1 | 1, l, r);
    else
        return (Query(i << 1, l, mid) + Query(i << 1 | 1, mid + 1, r));
}
int main(int argc, char const* argv[])
{
    // freopen("RAW\\in.txt", "r", stdin);
    // freopen("RAW\\out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    Build(1, 1, n);
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a == b) printf("0\n");
        else {
            int temp = Query(1, a, b);
            printf("%d\n", temp / 10);
        }
    }
    
    return 0;
}