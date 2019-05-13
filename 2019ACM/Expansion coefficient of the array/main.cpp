#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = min(a[1], a[n])/(n-1);
    for(int i = 2; i < n; i++) {
        int temp1 = min(a[1], a[i])/(i-1);
        int temp2 = min(a[i], a[n])/(n-i);
        ans = min(temp1, ans);
        ans = min(temp2, ans);
    }
    printf("%d\n", ans);
    return 0;
}
