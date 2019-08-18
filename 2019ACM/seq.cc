#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        long long n;
        scanf("%lld", &n);
        if(n == 1 || n == 2) printf("1\n");
        else {
            n -= 2;
            long long ans = -1;
            if(n%6==1 || n%6==3) ans = n/6;
            else if(n%6==2) ans = 3+(n/6)*6;
            else if(n%6==4) ans = 3+(n/6)*3;
            else if(n%6==5) ans = 5+(n/6)*4;
            else ans = 4+(n/6-1)*3;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
