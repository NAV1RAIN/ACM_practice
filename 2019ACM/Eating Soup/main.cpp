#include <bits/stdc++.h>
using namespace std;
int ans[1005];
int main() {
    int n, m;
    int t = 1;
    ans[0] = t;
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n/2; i++) {
        ans[i] = t++;
    }
    t--;
    if(n%2 == 1) {
        ans[i++] = t--;
        for(; i <= n; i++) ans[i] = t--;
    } else {
        t--;
        for(; i <= n; i++) ans[i] = t--;
    }
    printf("%d\n", ans[m]);
    return 0;
}
