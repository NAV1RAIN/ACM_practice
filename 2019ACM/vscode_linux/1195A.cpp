#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1005;
int arr[SIZE];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        arr[a]++;
    }
    int jl = 0;
    int t = 0;
    int tt = (n/2+(n%2 == 0?0:1))*2;
    for(int i = 1; i <= k && tt != 0; i++) {
        if(arr[i] >= tt) {
            t = (n/2+(n%2 == 0?0:1))*2;
            tt = 0;
            break;
        } else {
            t += arr[i]/2*2;
            tt -= arr[i]/2*2;
            if(arr[i]%2 == 1) jl++;
        }
    }
    if(tt/2 > jl) t += jl;
    else t += tt/2; 
    printf("%d\n", t);
    return 0;
}