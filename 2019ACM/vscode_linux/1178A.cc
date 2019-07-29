#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n;
    long long sum = 0;
    int maxx = 0;
    int mm = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    long long hh = 0;
    int jl = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[0]/2) hh += a[i], jl++;
    }
    if(hh >= sum-hh) printf("%d", 0);
    else {
        printf("%d\n1", n-jl);
        for(int i = 1; i < n; i++) {
            if(a[i] <= a[0]/2) printf(" %d", i+1);
        }
    }
    return 0;
}