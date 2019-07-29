#include <bits/stdc++.h>
using namespace std;
int noprime[2005];
int tot;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    for(int i = 2; i <= 2000; i++) {
        int tt = sqrt(i);
        for(int j = 2; j <= tt; j++) {
            if(i%j == 0) {
                noprime[i] = true;
                break;
            }
        }
    }
    int n;
    scanf("%d", &n);
    int tt = n;
    int jl = -1;
    while(1) {
        if(!noprime[tt]) {
            jl = tt;
            break;
        } else tt++;
    }
    printf("%d\n", tt);
    tt -= n;
    for(int i = 1; i <= n; i++) {
        printf("%d %d\n", i, i%n+1);
    }
    for(int i = 1; i <= n && tt; i++) {
        printf("%d %d\n", i, n-i);
        tt--;
    }
    return 0;
}