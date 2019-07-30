#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        long long k, n;
        scanf("%lld%lld", &k, &n);
        int ceng = 0;
        long long temp = 0;
        while(temp <= n) {
            temp += pow(k, ceng);
            ceng++;
            // temp /= k;
        }
        // if(k != 2) ceng++;
        if(ceng <= 2) {
            if(n > 2) {
                printf("2\n");
            } else printf("1\n");
            continue;
        }
        int num_s = (pow(k, ceng-1)-1)/(k-1);
        int num_m = n-num_s;
        int hh = pow(k, ceng-2);
        if(hh >= num_m) {
            printf("%d\n", (ceng-1)*2-1);
        } else {
            printf("%d\n", (ceng-1)*2);
        }
    }
    return 0;
}