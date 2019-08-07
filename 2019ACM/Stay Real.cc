#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
long long arr[SIZE];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
        }
        sort(arr, arr + n);
        long long ans1 = 0, ans2 = 0;
        int hh = 1;
        for(int i = n-1; i >= 0; i--) {
            if(hh > 0) ans1 += arr[i];
            else ans2 += arr[i];
            hh *= -1;
        }
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}