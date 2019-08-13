#include <bits/stdc++.h>
using namespace std;

char str[20];

char tt[100005];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n;
    scanf("%d%s", &n, tt);
    for(int i = 0; i < 10; i++) str[i] = '0';
    for(int i = 0; i < n; i++) {
        if(tt[i] == 'L') {
            for(int i = 0; i < 10; i++) {
                if(str[i] == '0') {
                    str[i] = '1';
                    break;
                }
            }
        } else if(tt[i] == 'R') {
            for(int i = 9; i >= 0; i--) {
                if(str[i] == '0') {
                    str[i] = '1';
                    break;
                }
            }
        } else {
            int hh = tt[i]-'0';
            str[hh] = '0';
        }
    }
    printf("%s\n", str);
    return 0;
}