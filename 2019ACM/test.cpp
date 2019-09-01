#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll MAXN = 1000050;
ll a[MAXN], mod[MAXN];
ll n, p;
bool fg;

inline ll pro(ll x, ll md) { return x < md ? x : x % md + md; }
inline ll mi(ll x, ll y, ll md) {
    ll z = 1;
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
	freopen("RAW/in", "r", stdin);
	freopen("RAW/out", "w", stdout);
    ll x, y;
    int T;
    scanf("%d", &T);
    while (T--) {
		ll tt;
		scanf("%lld", &tt);
        scanf("%lld", &n);
        scanf("%lld", &mod[1]);
		if(n == 0 || tt == 1) {
			if(mod[1] == 1) printf("0\n");
			else printf("1\n");
			continue;
		}
        for (ll i = 1; mod[i] > 1; ++i) {
            mod[i + 1] = x = mod[i];
            for (ll j = 2; j * j <= x; ++j) {
                for (fg = 0; x % j == 0; x /= j, fg = true)
                    ;
                if (fg) mod[i + 1] = 1LL * mod[i + 1] * (j - 1) / j;
            }
            if (x > 1) mod[i + 1] = 1LL * mod[i + 1] * (x - 1) / x;
        }
        for (ll i = 1; i <= n; ++i) a[i] = tt;
        printf("%lld\n", dfs(1, 1, n) % mod[1]);
    }
    return 0;
}