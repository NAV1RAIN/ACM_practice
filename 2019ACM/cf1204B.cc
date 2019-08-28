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
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    LL minn = pow(2, l)-1+(n-l);
    LL maxx = pow(2, r)-1+(pow(2, r-1))*(n-r);
    printf("%lld %lld\n", minn, maxx);
    return 0;
}
