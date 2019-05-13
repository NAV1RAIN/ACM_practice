#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
int b[SIZE], g[SIZE];
bool
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &g[i]);
        if(i < m && g[i] == 1) g[i] = 0;
    }
    sort(b, b+n);
    sort(g, g+m);
    bool flag = true;
    int ans = 0;
    int tt = m-1;
    int i;
    for(i = n-1; i >= 0 && flag && tt >= 0; i--) {
        if(b[i] > g[0]) flag = false;
        ans += g[tt];
        g[tt--] = -1;
        ans += (m-1)*b[i];
    }
    if(tt != -1) {
        for(; tt >= 0; tt--) {
            ans += (g[tt]-b[n-1])*n;
        }
    } else {
        for(; i >= 0; i--) {
            ans += m*b[i];
        }
    }
    if(flag) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
