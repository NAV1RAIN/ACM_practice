#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int SIZE = 1e5+5;
//int arr[SIZE];
long long qmod(long long a, long long b) {
    long long ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%MOD;
        }
        b /= 2;
        a = (a*a) % MOD;
    }
    return ans;
}
int main() {
//    freopen("in.cc", "r", stdin);
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long temp;
        scanf("%lld", &temp);
        long long jl = 0;
        long long tt = temp;
        long long t1 = 0;
        while(tt != 0) {
            long long f = qmod(10, jl);
            long long ttt = (tt%10)*f%MOD;
//            printf("%lld\n", ttt);
            ans = (ans + ((ttt%MOD)*n)%MOD)%MOD;
//            printf("%lld\n", ans);
            jl += 2;
            tt /= 10;
        }
        tt = temp;
        jl = 1;
        while(tt != 0) {
            long long f = qmod(10, jl);
            long long ttt = (tt%10)*f%MOD;
//            cout << ttt << '\n';
            ans = (ans + ((ttt%MOD)*n)%MOD)%MOD;
            jl += 2;
            tt /= 10;
        }
    }
    printf("%lld\n", ans%MOD);
    return 0;
}
