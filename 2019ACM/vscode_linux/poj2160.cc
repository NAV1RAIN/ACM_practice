#include <stdio.h>
#include <algorithm>
using namespace std;
bool ok[10];
struct Node {
    int a, b;
    bool operator!=(const Node& x) const {
        if (x.a == a && x.b == b) {
            return false;
        } else
            return true;
    }
    bool operator<(const Node& x) const {
        if (x.a != a)
            return a < x.a;
        else
            return b < x.b;
    }
} len[10];

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    for (int i = 0; i < 6; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        len[i].a = a, len[i].b = b;
    }
    bool flag = true;
    sort(len, len + 6);
    for (int i = 0; i < 6 && flag; i += 2) {
        if (len[i] != len[i + 1]) flag = false;
    }
    if(!flag) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int a = -1, b = -1;
    if(len[0].a == len[2].a) a = len[0].b, b = len[2].b;
    else if(len[0].a == len[2].b) a = len[0].b, b = len[2].a;
    else if(len[0].b == len[2].b) a = len[0].a, b = len[2].a;
    else if(len[0].b == len[2].a) a = len[0].a, b = len[2].b;
    if((a == len[4].a && b == len[4].b) || (a == len[4].b && b == len[4].a)) {
        flag = true;
    } else flag = false;
    printf("%s\n", flag ? "POSSIBLE" : "IMPOSSIBLE");
    return 0;
}