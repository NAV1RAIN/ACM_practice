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
LL cost[1010][1010];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(cost, LNF, sizeof(cost));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int a, b;
            LL c;
            scanf("%d%d%lld", &a, &b, &c);
            a++;
            b++;
            cost[a][b] = c;
            // printf("%lld\n", cost[a][b]);
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (cost[i][j] > cost[i][k] + cost[k][j]) {
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < 6; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a++;
            b++;
            // printf("%d %d\n", a, b);
            LL temp = -cost[b][a];
            cost[a][b] = temp;
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (cost[i][j] > cost[i][k] + cost[k][j]) {
                            cost[i][j] = cost[i][k] + cost[k][j];
                        }
                    }
                }
            }
            printf("%lld\n", temp);
        }
    }
    return 0;
}
