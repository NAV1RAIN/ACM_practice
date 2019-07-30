#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int cmp(const int &a, const int &b) { return a > b; }
int b[MAXN], g[MAXN];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n, m;
    int mx, mi;
    mx = -1;
    mi = 0x3f3f3f3f;
    LL ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        ans += (LL)b[i] * m;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &g[i]);
        ans += (LL)g[i];
    }
    sort(b, b + n);
    sort(g, g + m);

    if (b[n - 1] > g[0]) {
        ans = -1;
    } else if (b[n - 1] != g[0]) {
        ans -= (LL)b[n - 1] * (m - 1) + b[n - 2];
    } else {
        ans -= (LL)b[n - 1] * m;
    }
    printf("%lld\n", ans);
    return 0;
}