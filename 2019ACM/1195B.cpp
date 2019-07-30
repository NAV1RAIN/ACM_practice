#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long temp = 2*n+2*k;
    long long l = 1, r = 1000000000;
    long long ans = 0;
    while(l <= r) {
        long long mid = (l+r)/2;
        if(mid*(mid+3) > temp) r = mid - 1;
        else if(mid*(mid+3) < temp) l = mid + 1;
        else {
            ans = mid;
            break;
        }
    }
    printf("%lld\n", n-ans);
    return 0;
}