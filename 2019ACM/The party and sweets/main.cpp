#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e8+5;
const long long SIZE = 1e5+5;
long long b[SIZE], g[SIZE];
int main() {
    long long n, m, ans = 0;
    scanf("%lld%lld", &n, &m);
    for(long long i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        ans += b[i] * m;
    }
    for(long long i = 0; i < m; i++) {
        scanf("%lld", &g[i]);
    }
    sort(b, b+n);
    sort(g, g+m);
    if(b[n-1] > g[0]) return cout << "-1" << '\n', 0;
    for(long long i = 0; i < m; i++) {
        ans += g[i]-b[n-1];
    }
    if(g[0] != b[n-1]) {
        ans += (g[0] - b[n-2])-(g[0] - b[n-1]);
    }
    printf("%lld\n", ans);
    return 0;
}
