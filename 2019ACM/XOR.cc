#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull quickpow(ull a, ull b, ull c) {
	ull ans = 1;
	a = a%c;
	while(b != 0) {
		if(b & 1) ans = (ans*a)%c;
		b >>= 1;
		a = (a*a)%c;
	}
	return ans;
}
int main() {
	ull n, k, p;
	scanf("%llu%llu%llu", &n, &k, &p);
	if(p == 2) {
		printf("0\n");
		return 0;
	}
	ull t1 = quickpow(2, n, p-1);
	t1 = (t1-n%(p-1)+(p-1))%(p-1);
	ull ans = quickpow(2, t1, p);
	if(k == 0) ans--;
	cout << ans << '\n';
	return 0;
}
