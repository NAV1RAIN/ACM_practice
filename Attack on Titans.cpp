#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const long long MOD = 1000000007;
const long long SIZE = 1e6 + 10;
long long dp[5][SIZE];

long long solve(long long u, long long h, long long n)
{
    dp[0][0] = dp[1][0] = 0, dp[2][0] = 1;
    for (long long i = 0; i < n; i++) {
        long long sum = (dp[0][i] + dp[1][i] + dp[2][i]) % MOD;
        dp[2][i + 1] = sum;
        if (i < u)
            dp[0][i + 1] = sum;
        else if (i == u)
            dp[0][i + 1] = ((sum - 1) % MOD + MOD) % MOD;
        else
            dp[0][i + 1] = ((sum - dp[1][i - u] - dp[2][i - u]) % MOD + MOD) % MOD;

        if (i < h)
            dp[1][i + 1] = sum;
        else if (i == h)
            dp[1][i + 1] = ((sum - 1) % MOD + MOD) % MOD;
        else
            dp[1][i + 1] = ((sum - dp[2][i - h] - dp[0][i - h]) % MOD + MOD) % MOD;
    }
    return (dp[0][n] + dp[1][n] + dp[2][n]) % MOD;
}

int main(int argc, char const* argv[])
{
    long long n, m, k;
    while (scanf("%lld%lld%lld", &n, &m, &k) > 0) {
        printf("%lld\n", ((solve(n, k, n) - solve(m - 1, k, n)) % MOD + MOD) % MOD);
    }
    return 0;
}
