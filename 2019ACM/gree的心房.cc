#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    long long ans = n+m-2;
    if(((long long)n*m-(ans+1)) < k) ans = -1;
    printf("%lld\n", ans);
    return 0;
}