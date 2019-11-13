#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e4+5;
struct node{
    int a, b, g, k;
} arr[SIZE];
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &arr[i].a, &arr[i].b, &arr[i].g, &arr[i].k);
    }
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = -1;
    for(int i = n-1; i >= 0; i--) {
        if(arr[i].a <= a && arr[i].a+arr[i].g >= a && arr[i].b <= b && arr[i].b+arr[i].k >= b) {
            ans = i + 1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}