#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, k;
int len;
const int MAXN = 27005;
const int INF = 0x3f3f3f3f;
int arr[MAXN];
int brr[MAXN];
int id[MAXN];
int tree[MAXN];
int upp[MAXN], low[MAXN];
LL lowbit(LL x) {
    return x & (-x);
}
void modify(LL x, LL add) {
    if(x == 0) return;
    while(x<=MAXN) {
        tree[x]+=add;
        x+=lowbit(x);
    }
}
LL get_sum(LL x) {
    int ret=0;
    while(x > 0) {
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
    for(int i = 1; i <= m; i++) {
        while(R < node[i].R) {
            R++;
            modify(id[R], 1);
            temp += get_sum(upp[R])-get_sum(low[R]);
        }
        while(R > node[i].R) {
            temp -= get_sum(upp[R])-get_sum(low[R]);
            modify(id[R], -1);
            R--;
        }
        while(L < node[i].L) {
            temp -= get_sum(upp[L])-get_sum(low[L]);
            modify(id[L], -1);
            L++;
        }
        while(L > node[i].L) {
            L--;
            modify(id[L], 1);
            temp += get_sum(upp[L])-get_sum(low[L]);
        }
        ans[node[i].id] = temp;
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    memset(brr, INF, sizeof(brr));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        brr[i] = arr[i];
    }
    sort(brr+1, brr+1+n);
    len = unique(brr+1, brr+1+n)-(brr+1);
//    for(int i = 1; i <= len; i++) {
//        printf("%d\n", brr[i]);
//    }
    for(int i = 1; i <= n; i++) {
        id[i] = lower_bound(brr+1, brr+1+len, arr[i])-(brr);
    }
    for(int i = 1; i <= len; i++) {
        upp[i] = upper_bound(brr+1, brr+1+len, brr[i]+k)-(brr);
        low[i] = lower_bound(brr+1, brr+1+len, brr[i]-k)-(brr);
//        low[i] = i;
        upp[i]--;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d %d\n", brr[id[i]], id[i]);
    }
    for(int i = 1; i <= len; i++) {
        printf("%d %d %d\n", low[i], upp[i], brr[i]);
    }
    for(int i = 1; i <= m; i++) {
        node[i].id = i;
        scanf("%d%d", &node[i].L, &node[i].R);
    }
    unit = (int)sqrt(n);
    sort(node+1, node+1+m, cmp);
    for(int i = 1; i <= m; i++) {
        printf("%d %d\n", node[i].L, node[i].R);
    }
    work();
    for(int i = 1; i <= m; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
