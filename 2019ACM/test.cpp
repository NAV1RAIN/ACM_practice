#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in", "r", stdin);
    long long n, m;
    while(~scanf("%lld%lld", &n, &m)) {
        if(n*2 >= m) printf("%lld\n", (n+m)/3);
        else {
            printf("%lld\n", n);
        }
    }
    return 0;
}