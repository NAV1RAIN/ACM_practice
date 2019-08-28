#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        int p1, p2;
        scanf("%d%d%d", &a, &b, &c);
        scanf("%d%d", &p1, &p2);
        int mm = min(a/2,b);
        int nn = min(a/2,c);
        int ans = 0;
        if(p1 > p2) {
            ans = mm*p1;
            a -= mm*2;
            ans += min(a/2,c)*p2;
        } else {
            ans = nn*p2;
            a -= nn*2;
            ans += min(a/2,b)*p1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
