#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int SIZE = 2500;
int a[55], b[55], w[55][SIZE];
int dp[55][(SIZE << 1) + 5];
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= 50; i++) {
        for(int j = 0; j <= (SIZE << 1); j++) {
            dp[i][j] = -1e8;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &w[i][j]);
        }
    }
    dp[0][2500] = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = 5000; k >= 0; k--) {
                if(dp[i][k] != dp[0][0]) {
                    dp[j][k+a[j]] = max(dp[j][k+a[j]], dp[i][k]+b[j]+w[i][j]);
                }
            }
        }
    }
    int ans = dp[0][0];
    for(int i = 1; i <= n; i++) {
        ans = max(dp[i][2500+m], ans);
    }
    if(ans == dp[0][0]) ans = -1;
    printf("%d\n", ans);
    return 0;
}
