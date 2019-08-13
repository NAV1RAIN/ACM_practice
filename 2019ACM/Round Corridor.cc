#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int q;
    long long n, m;
    scanf("%lld%lld%d", &n, &m, &q);
    long long fuck = __gcd(n, m);
    n /= fuck, m /= fuck;
    while(q--) {
        long long s1, s2, e1, e2;
        scanf("%lld%lld%lld%lld", &s1, &s2, &e1, &e2);
        long long f1, f2;
        if(s1 == 1) f1 = (s2 - 1) / n;
        else f1 = (s2 - 1) / m;
        if(e1 == 1) f2 = (e2 - 1) / n;
        else f2 = (e2 - 1) / m;
        if(f1 == f2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}