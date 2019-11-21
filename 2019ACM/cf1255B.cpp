#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2005;
int arr[SIZE];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            ans += arr[i];
        }
        if(n == 2) {
            printf("-1\n");
            continue;
        }
        if(m < n) {
            printf("-1\n");
            continue;
        }
        ans *= 2;
        int jl = -1;
        int minn = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++) {
            if(minn > arr[i]) {
                minn = arr[i];
                jl = i;
            }
        }
        long long temp = minn;
        minn = 0x3f3f3f3f;
        int jl2 = -1;
        for(int i = 1; i <= n; i++) {
            if(minn > arr[i] && jl != i) {
                minn = arr[i];
                jl2 = -1;
            }
        }
        temp += minn;
        ans += (m-n)*temp;
        printf("%lld\n", ans);
        for(int i = 1; i < n; i++) {
            printf("%d %d\n", i, i+1);
        }
        printf("%d 1\n", n);
        for(int i = n; i < m; i++) {
            if(jl2 != -1) printf("%d %d\n", jl, jl2);
            else if(jl != n) printf("%d %d\n", jl, jl+1);
            else printf("%d %d\n", jl-1, jl);
        }
    }
    return 0;
}