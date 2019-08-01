#include <bits/stdc++.h>
using namespace std;
const int SIZE = 3e5+5;
int a[SIZE];
int b[SIZE];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; i++) {
        b[i] = a[i]-a[i-1];
    }
    if(n == k) printf("0\n");
    else {
        long long sum = 0;
        for(int i = 1; i < n; i++) {
            sum += b[i];
        }
        sort(b+1, b+n);
        for(int i = 1; i <= k-1; i++) {
            sum -= b[n-i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
