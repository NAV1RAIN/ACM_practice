#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define MN 1000050
using namespace std;
ll a[MN], mod[MN];
ll n, p;
bool fg;

inline ll read() {
    ll n = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n * f;
}

inline ll pro(ll x, ll md) { return x < md ? x : x % md + md; }
inline ll mi(ll x, ll y, ll md) {
    register ll z = 1;
    for (; y; x = pro(1LL * x * x, md), y >>= 1)
        if (y & 1) z = pro(1LL * z * x, md);
    return z;
}

ll dfs(ll x, ll y, ll lim) {
    if (x == lim) return a[x] >= mod[y] ? a[x] % mod[y] + mod[y] : a[x];
    if (mod[y] == 1) return 1;
    return mi(a[x], dfs(x + 1, y + 1, lim), mod[y]);
}

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    ll i, j, x, y;
    int T;
    scanf("%d", &T);
    while (T--) {
        ll tt;
        tt = read(); n = read(); mod[1] = read();
        for (i = 1; mod[i] > 1; ++i) {
            mod[i + 1] = x = mod[i];
            for (j = 2; j * j <= x; ++j) {
                for (fg = 0; x % j == 0; x /= j, fg = true)
                    ;
                if (fg) mod[i + 1] = 1LL * mod[i + 1] * (j - 1) / j;
            }
            if (x > 1) mod[i + 1] = 1LL * mod[i + 1] * (x - 1) / x;
        }
        for (i = 1; i <= n; ++i) a[i] = tt;
        printf("%lld\n", dfs(1, 1, n) % mod[1]);
    }
    return 0;
}