#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
const long long MOD = 998244353;
long long arr[SIZE];
int len[SIZE];
int a[20];
long long qmod(long long a, long long b) {
    long long ans = 1;
    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        b >>= 1;
        a = (a*a)%MOD;
    }
    return ans;
}
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        long long temp = arr[i];
        int jl = 0;
        while(temp) {
//            cout << temp << '\n';
            jl++;
            temp /= 10;
        }
        len[i] = jl;
//        printf("%d\n", jl);
        a[jl]++;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
//        printf("%d:\n\n", arr[i]);
        for(int j = 1; j <= 10; j++) {
            long long temp = arr[i];
            int jl = 1;
            int ll = 1;
            while(temp) {
                long long ff = qmod(10, jl);
//                if(a[j] != 0) printf("%lld\n", temp%10*ff);
                ans = (ans + (temp%10)*ff*(a[j])%MOD)%MOD;  //-(len[i]==j?1:0)
                temp /= 10;
                if(ll+1 <= j) {
                    jl += 2, ll++;
                } else {
                    jl++, ll++;
                }
            }
        }
    }
//    printf("%d\n", ans);
    for(int i = 0; i < n; i++) {
//        printf("\n%d:\n\n", arr[i]);
        for(int j = 1; j <= 10; j++) {
            long long temp = arr[i];
            int jl = 0;
            int ll = 1;
            while(temp) {
                long long ff = qmod(10, jl);
//                if(a[j] != 0) printf("%lld\n", temp%10*ff);
                ans = (ans + (temp%10)*ff*(a[j])%MOD)%MOD;  //-(len[i]==j?1:0)
                temp /= 10;
                if(ll <= j) {
                    jl += 2, ll++;
                } else {
                    jl++, ll++;
                }
            }
        }
    }
    printf("%lld\n", ans%MOD);
    return 0;
}
