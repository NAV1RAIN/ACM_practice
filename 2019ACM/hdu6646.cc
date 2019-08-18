#include <bits/stdc++.h>
using namespace std;
const int SIZE = 3e5+5;
char s[SIZE];
int len[5];
void sc(int tt[], int jj) {
    scanf("%s", s);
    int i;
    for(i = 0; s[i] != 0; i++) {
        tt[i+1] = s[i]-'0';
    }
    len[jj] = i;
}
int t1[SIZE], t2[SIZE], t3[SIZE];
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(t1, 0, sizeof(t1));
        memset(t2, 0, sizeof(t2));
        memset(t3, 0, sizeof(t3));
        sc(t1, 1);
        sc(t2, 2);
        sc(t3, 3);
    }
    return 0;
}