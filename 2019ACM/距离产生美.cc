#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
const long long MAXN = 1e18;
long long arr[SIZE];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n, k;
    int ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if(i > 0) {
            if(abs(arr[i]-arr[i-1]) < k) {
                arr[i] = MAXN;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}