#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5+5;
int h1[SIZE], h2[SIZE];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &h1[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &h2[i]);
    }
    long long ans[2][SIZE];
    ans[0][0] = h1[0];
    ans[1][0] = h2[0];
    for(int i = 1; i < n; i++) {
        ans[0][i] = max(ans[0][i-1], ans[1][i-1]+h1[i]);
        ans[1][i] = max(ans[1][i-1], ans[0][i-1]+h2[i]);
    }
    printf("%lld\n", max(ans[0][n-1], ans[1][n-1]));
    return 0;
}