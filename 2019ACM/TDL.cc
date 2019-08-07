#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e4 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long arr[SIZE];
int tol;
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        tol = 0;
        memset(arr, 0, sizeof(arr));
        long long k, m;
        long long ans = INF;
        scanf("%lld%lld", &k, &m);
        bool flag = false;
        for (long long i = 1; i <= 1000; i++) {
            long long n = i ^ k;
            int jl = 0;
            for (long long j = 1; j <= 1000 && jl <= m; j++) {
                if (__gcd(n, n + j) == 1) {
                    jl++;
                    if (jl == m) {
                        flag = true;
                        ans = min(ans, n + j);
                        break;
                    }
                }
            }
        }
        if (flag) {
            printf("%lld\n", ans);
        } else
            printf("-1\n");
    }
    return 0;
}