#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int SIZE = 2e5 + 5;
char str[SIZE];
int arr[SIZE];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", str);
        int l1, l2;
        LL ans = 0;
        l1 = l2 = -1;
        if (a*2 >= b) {
            for (int i = 0; i < n; i++) {
                if (str[i] == '1') {
                    l1 = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (str[i] == '1') {
                    l2 = i;
                    break;
                }
            }
            if (l1 != -1 && l2 != -1) {
                ans = ((LL)l2 - l1 + 2 + n + 1) * (LL)b + ((LL)n + 2) * (LL)a;
            } else {
                ans = (LL)((LL)n + 1) * (LL)b + (LL)n * a;
            }
        } else {
            int len = 0;
            for (int i = 0; i < n; i++) {
                if (i == 0 || str[i] == '0')
                    arr[i] = str[i] - '0';
                else if (str[i] == '1')
                    arr[i] = str[i] - '0' + arr[i - 1];
            }
            ans = (LL)(n+1)*b+(LL)n*a;
            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] != 0) {
                    ans += (LL)(arr[i]+1)*b+(LL)2*a;
                    i -= arr[i] - 1;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
