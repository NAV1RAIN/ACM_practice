#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int SN = 3e3+5;
const int SM = 5e5+5;
inline LL multiMod(LL a, LL b) {
    LL res = 0;
    while(b) {
        if(b & 1) {
            res = (res + a) % MOD;
        }
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}
void DFS() {

}
int main() {
    int n, m;
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int test;
    scanf("%d", &test);
    for(int i = 2; i <= test; i++) {
        LL a = 1 + i, b = i;
        i & 1 ? a /= 2 : b /= 2;
        LL TT = multiMod(a, b);
        printf("%lld\n", TT);
    }
//    while(~scanf("%d%d", &n, &m)) {
//        for(int i = 0; i < m; i++) {
//            int a, b;
//            scanf("%d%d", &a, &b);
//        }
//    }
    return 0;
}