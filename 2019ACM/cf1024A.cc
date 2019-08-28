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
const int SIZE = 105;
char ss[SIZE];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    scanf("%s", ss);
    int len = strlen(ss);
    bool flag = false;
    if(len%2==1) for(int i = 1; i < len; i++) {
        if(ss[i] == '1') flag = true;
    }
    printf("%d\n", len/2+(flag));
    return 0;
}
