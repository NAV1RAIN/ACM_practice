#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int ans = 0;
    bool flag = true;
    for(int i = 1; i < n && flag; i++) {
        if(arr[i-1] == 1) {
            if(arr[i] == 1) flag = false;
            else if(arr[i] == 2) ans += 3;
            else if(arr[i] == 3) ans += 4;
        } else if(arr[i-1] == 2) {
            if(arr[i] == 1) ans += 3;
            else if(arr[i] == 2) ans += 3;
            else if(arr[i] == 3) flag = false;
        } else if(arr[i-1] == 3) {
            if(arr[i] == 1) ans += 4;
            else if(arr[i] == 2) flag = false;
            else if(arr[i] == 3) flag = false;
        }
    }
    if(flag) printf("Finite\n%d\n", ans);
    else printf("Infinite\n");
    return 0;
}