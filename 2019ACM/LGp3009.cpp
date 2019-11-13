#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n;
    scanf("%d", &n);
    int ans = -1;
    int t1, t2;
    scanf("%d", &t1);
    ans = t1;
    for(int i = 1; i < n; i++) {
        scanf("%d", &t2);
        t1 = max(t2, t1 + t2);
        ans = max(ans, t1);
    }
    printf("%d\n", ans);
    return 0;
}