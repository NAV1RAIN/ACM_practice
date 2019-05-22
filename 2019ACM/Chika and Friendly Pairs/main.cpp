#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, k;
int len;
const int MAXN = 27005;
int arr[MAXN];
int brr[MAXN];
int id[MAXN];
int tree[MAXN];
LL lowbit(LL x) {
    return x & (-x);
}
void modify(LL x, LL add) { //һά
    while(x<=MAXN) {
        tree[x]+=add;
        x+=lowbit(x);
    }
}
LL get_sum(LL x) {
    int ret=0;
    while(x!=0) {
        ret+=tree[x];
        x-=lowbit(x);
    }
    return ret;
}
struct Query {
    int L, R, id;
}node[MAXN];
LL ans[MAXN];
int a[MAXN];
int unit;
bool cmp(const Query& a, const Query& b) {
    if(a.L/unit != b.L/unit) return a.L/unit < b.L/unit;
    else return a.R < b.R;
}
void work() {
    LL temp = 0;
    int L = 1;
    int R = 0;
    int l, r;
    for(int i = 0; i < m; i++) {
        while(R < node[i].R) {
            R++;
            modify(id[i], 1);
        }
        while(R > node[i].R) {
            modify(id[i], -1);
            R--;
        }
        while(L < node[i].L) {
            modify(id[i], -1);
            L++;
        }
        while(L > node[i].L) {
            L--;
            modify(id[i], 1);
        }
    }
    ans[node[i].id] = temp;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        brr[i] = arr[i];
    }
    sort(brr+1, brr+1+n);
    len = unique(brr+1, b+1+n)-(b+1);
    for(int i = 1; i <= n; i++) {
        id[i] = lower_bound(brr+1, brr+1+len, arr[i])-(len+1);
    }
    for(int i = 0; i < m; i++) {
        node[i].id = i;
        scanf("%d%d", &node[i].L, &node[i].R);
    }
    unit = (int)sqrt(n);
    sort(node, node+m, cmp);
    work();
    for(int i = 0; i < m; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
