#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    long long ans = 1;
    int hh = a+b;
    while(hh--) {
        ans = ans*2%MOD;
    }
    printf("%lld\n", ans);
    return 0;
}