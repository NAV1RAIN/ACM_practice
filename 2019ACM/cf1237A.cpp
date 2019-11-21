#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int flag = 1;
    int n;
    scanf("%d", &n);
    while(n--) {
        int t;
        scanf("%d", &t);
        if(t&1) {
            if(flag == 1) {
                if(t > 0) printf("%d\n", t/2+1);
                else if(t < 0) printf("%d\n", t/2);
            } else if(flag == -1) {
                if(t > 0) printf("%d\n", t/2);
                else if(t < 0) printf("%d\n", t/2-1);
            }
            flag *= -1;
        } else {
            printf("%d\n", t/2);
        }
    }
    return 0;
}