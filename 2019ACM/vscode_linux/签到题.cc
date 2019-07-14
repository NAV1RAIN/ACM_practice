#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        if(l == r) {
            printf("%lld %lld %lld %lld\n", l, l, l, l);
        } else {
            printf("%lld %lld %lld 1\n", r*(r-1), l, r);
        }
    }
    return 0;
}