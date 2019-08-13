#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 2010, M = 4100;
int Case, n, m, i, j, k, cb, b[N], pos[N];  //pos记录单点在线段树中的位置
//pre为区间最大前缀和，suf为区间最大后缀和，s为区间和，v为区间最大子段和
ll pre[M], suf[M], s[M], v[M], ans;
struct E {
    int x, y, z;
} e[N];
inline bool cmp(const E& a, const E& b) { return a.x < b.x; }
void build(int x, int a, int b) {
    int ls = x << 1, rs = x << 1 | 1;  //ls为左区间， rs为右区间
    pre[x] = suf[x] = s[x] = v[x] = 0;
    if (a == b) {
        pos[a] = x;
        return;
    }
    int mid = (a + b) >> 1;
    build(ls, a, mid), build(rs, mid + 1, b);
}
inline void change(int x, int p) {
    int ls, rs;  //ls为左区间， rs为右区间
    x = pos[x];
    s[x] += p;
    pre[x] = suf[x] = v[x] = (s[x] > 0 ? s[x] : 0);
    for (x >>= 1; x; x >>= 1) {
        ls = x << 1, rs = x << 1 | 1;
        pre[x] = max(pre[ls], s[ls] + pre[rs]);  //区间最大前缀和
        suf[x] = max(suf[rs], s[rs] + suf[ls]);  //区间最大后缀和
        s[x] = s[ls] + s[rs];  //区间之和
        v[x] = max(max(v[ls], v[rs]), suf[ls] + pre[rs]);  //区间最大子段和
    }
}
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        for (cb = 0, i = 1; i <= n; i++) {
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
            b[++cb] = e[i].y;  //记录行
        }
        sort(b + 1, b + cb + 1);  //将行排序
        for (m = 0, i = 1; i <= cb; i++) if (i == 1 || b[i] != b[m]) b[++m] = b[i];  //合并同一行的数据，m最后得到的是行数
        sort(e + 1, e + n + 1, cmp);
        ans = 0;
        for (i = 1; i <= n; i++) e[i].y = lower_bound(b + 1, b + m + 1, e[i].y) - b;  //行离散化
        for (i = 1; i <= n; i++)
            if (i == 1 || e[i].x != e[i - 1].x) {
                build(1, 1, m);
                for (j = i; j <= n; j = k) {
                    for (k = j; k <= n && e[j].x == e[k].x; k++) {
                        change(e[k].y, e[k].z);
                    }
                    if (ans < v[1]) ans = v[1];
                }
            }
        printf("%lld\n\n", ans);
    }
}