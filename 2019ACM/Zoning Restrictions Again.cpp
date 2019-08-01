#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100;
int height[SIZE];
int l, r, x;
int main() {
    int n, h, m;
    scanf("%d%d%d", &n, &h, &m);
    for(int i = 1; i <= n; i++) {
        height[i] = h;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &x);
        for(int j = l; j <= r; j++) {
            height[j] = min(x, height[j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += height[i]*height[i];
    }
    printf("%d\n", ans);
    return 0;
}