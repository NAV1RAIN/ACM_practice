#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        int temp = (b-a);
        int ans = 0;
        ans += temp/5;
        temp = temp-temp/5*5;
        ans += temp/2;
        temp = temp-temp/2*2;
        ans += temp;
        printf("%d\n", ans);
    }
    return 0;
}