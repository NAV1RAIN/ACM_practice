#include <bits/stdc++.h>
using namespace std;
const int SIZE = 3e5+5;
typedef unsigned long long ull;
ull gcd(ull x, ull y) {
	if(y) while((x%=y) && (y%=x));
	return x+y;
}
ull a[SIZE];
set<ull> ss;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	ull tt;
	scanf("%llu", &tt);
	for(int i = 1; i < n; i++) {
		ull temp;
		scanf("%llu", &temp);
		ss.insert(temp-tt);
	}
	auto it = ss.begin();
	ull jl = *it;
	bool flag = true;
	for(auto it = ss.begin(); it != ss.end(); it++) {
		if(it == ss.begin()) continue;
		else {
			ull hh = -1;
			if(*it % jl != 0) hh = gcd(*it, jl);
			if(hh != -1 && hh != 1) {
				jl = hh;
			} else if(hh == 1) {
				flag = false;
			}
		}
	}
	bool ok = false;
	for(int i = 0; i < m; i++) {
		ull temp;
		scanf("%llu", &temp);
		if(temp <= jl && jl%temp == 0) hh = i+1, ok = true;
		if(temp == 1) hh = i+1, ok = true;
	}
	if(flag && ok) printf("YES\n%llu %d\n", jl, hh);
	else printf("NO\n");
	return 0;
}
