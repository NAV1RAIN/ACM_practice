#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = max(max(a+b, a-b), a*b);
    printf("%d\n", ans);
    return 0;
}