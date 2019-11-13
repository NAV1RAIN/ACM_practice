#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e4+5;
int dp[SIZE];
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) {
        int fs, ti;
        scanf("%d%d", &fs, &ti);
        for(int j = ti; j <= m; j++) {
            dp[j] = max(dp[j], dp[j-ti]+fs);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}