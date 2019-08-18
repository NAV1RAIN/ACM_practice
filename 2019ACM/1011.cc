#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int SIZE = 1e6+5;
struct Node {
    LL a, b;
}arr[SIZE];
bool cmp(const Node& x, const Node& y) {
    if(x.a != y.a) return x.a < y.a;
    else return x.b > y.b;
}
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(arr, 0, sizeof(arr));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lld%lld", &arr[i].a, &arr[i].b);
        }
        Node maxx;
        maxx.a = 0x3f3f3f3f3f3f3f3f;
        maxx.b = 0;
        int jl = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i].b > maxx.b) {
                jl = i;
                maxx = arr[i];
            } else if(arr[i].b == maxx.b && arr[i].a < maxx.a) {
                jl = i;
                maxx = arr[i];
            }
        }
        swap(arr[0], arr[jl]);
        sort(arr+1, arr + n, cmp);
        LL ans = 0;
        LL temp1 = arr[0].b;
        LL temp2 = 0;
        arr[0].b = 0;
        for(int i = 1; i < n-1; i++) {
            if(arr[i].a <= temp1) {
                temp1 -= arr[i].a;
                ans += arr[i].a;
                temp2 += arr[i].b;
            } else {
                ans += 
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}