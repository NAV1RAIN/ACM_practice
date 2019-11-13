#include <bits/stdc++.h>
using namespace std;
const int S = 8;
long long mult_mod(long long a, long long b, long long c) {
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    while(b) {
        if(b & 1) {
            ret += tmp;
            if(ret > c) ret -= c;
        }
        tmp <<= 1;
        if(tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret;
}
long long pow_mod(long long a, long long n, long long mod) {
    long long ret = 1;
    long long temp = a % mod;
    while(n) {
        if(n & 1) ret = mult_mod(ret, temp, mod);
        temp = mult_mod(temp, temp, mod);
        n >>= 1;
    }
    return ret;
}
bool check(long long a, long long n, long long x, long long t) {
    long long ret = pow_mod(a, x, n);
    long long last = ret;
    for(int i = 1; i <= t; i++) {
        ret = mult_mod(ret, ret, n);
        if(ret == 1 && last != 1 && last != n - 1) return true;
        last = ret;
    }
    if(ret != 1) return true;
    else return false;
}
bool Miller_Rabin(long long n) {   //素数返回true,合数返回false
    if(n < 2) return false;
    if(n == 2) return true;
    if((n&1) == 0) return false;
    long long x = n-1;
    long long t = 0;
    while((x&1) == 0) {
        x >>= 1;
        t++;
    }
    srand(time(NULL));
    for(int i = 0; i < S; i++) {
        long long a = rand()%(n-1) + 1;
        if(check(a, n, x, t)) return false;
    }
    return true;
}
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    long long n;
    while(T--) {
        scanf("%lld", &n);
        if();
        if(!(Miller_Rabin(n - 2LL))) {
            if() printf("2 %d\n", n-2LL);
        }
        else if(!(Miller_Rabin(n - 3LL))) printf("3 %d\n", n-3LL);
        else printf("-1\n");
    }
    return 0;
}