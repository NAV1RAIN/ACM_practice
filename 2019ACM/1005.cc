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
struct Node {
    LL x, y;
    int l, r, id;
    Node() : l(-1), r(-1) {}
} arrl[SIZE], arrr[SIZE];
// struct TT {
//     int l, r;
// }
bool cmpx(const Node& a, const Node& b) {
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.id < b.id;
}
bool cmpy(const Node& a, const Node& b) {
    if (a.y != b.y)
        return a.y > b.y;
    else
        return a.id < b.id;
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(arrl, 0, sizeof(arrl));
        memset(arrr, 0, sizeof(arrr));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &arrl[i].x, &arrl[i].y);
            arrl[i].id = i + 1;
        }
        sort(arrl, arrl + n, cmpx);
        for (int i = 0; i < n; i++) {
            arrl[i].l = i + 1;
        }
        sort(arrl, arrl + n, cmpy);
        for (int i = 0; i < n; i++) {
            arrl[i].r = i + 1;
        }
        for (int i = 0; i < n; i++) {
            arrr[i] = arrl[i];
        }
        sort(arrl, arrl + n, cmpx);
        int jlx = n, jly = n;
        LL ans = LNF;
        for (int i = 0, j = 0; i < jlx && j < jly;) {
            if (arrl[i].id == arrr[j].id) {
                if (i < j)
                    i++;
                else if (j < i)
                    j++;
                else {
                    if (arrl[i].x > arrr[j].y) {
                        jly = min(jly, arrl[i].r);
                        i++;
                    } else if (arrl[i].x < arrr[j].y) {
                        jlx = min(jlx, arrr[j].l);
                        j++;
                    } else {
                        if (jlx < jly) {
                            jly = min(jly, arrl[i].r);
                            i++;
                        } else {
                            jlx = min(jlx, arrr[j].l);
                            j++;
                        }
                    }
                }
                continue;
            }
            LL t1 = abs(arrl[i].x - arrr[j].y);
            ans = min(t1, ans);
            if (arrl[i].x > arrr[j].y) {
                jly = min(jly, arrl[i].r);
                i++;
            } else if (arrl[i].x < arrr[j].y) {
                jlx = min(jlx, arrr[j].l);
                j++;
            } else if (arrl[i].x == arrr[j].y) {
                if (arrl[i].r > arrr[i].l) {
                    jly = min(arrl[i].r, jly);
                    i++;
                } else {
                    jlx = min(arrr[j].l, jlx);
                    j++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
