#include <bits/stdc++.h>
using namespace std;
const int SIZE = 105;
int arr[SIZE];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int t, n, m, k;
    scanf("%d", &t);
    while (t--) {
        memset(arr, 0, sizeof(arr));
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        bool flag = true;
        for(int i = 1; i < n; i++) {
            int temp = arr[i]-k>=0 ? arr[i]-k : 0;
            if(arr[i-1] + m < temp) {
                flag = false;
                break;
            }
            m = arr[i-1]+m-temp;
            // printf("%d\n", m);
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}