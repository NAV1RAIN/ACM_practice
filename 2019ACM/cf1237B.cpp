#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
int arr[SIZE];
int arr2[SIZE];
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int tt;
        cin >> tt;
        arr[tt] = i;
    }
    int minn = 0x3f3f3f3f;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr2[i];
    }
    for(int i = n; i >= 1; i--) {
        if(arr[arr2[i]] > minn) ans++;
        else minn = arr[arr2[i]];
    }
    printf("%d\n", ans);
    return 0;
}