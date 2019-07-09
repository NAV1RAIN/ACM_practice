#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    // freopen("RAW\\in.txt", "r", stdin);
    // freopen("RAW\\out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    bool flag = true;
    if(a[n-1] >= (a[0]+a[n-2])) {
        if(a[n-1] < (a[n-2] + a[n-3])) {
            int temp = a[n-1];
            a[n-1] = a[n-2];
            a[n-2] = temp;
        } else {
            flag = false;
        }
    }
    if(flag) {
        printf("YES\n%d", a[0]);
        for(int i = 1; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}