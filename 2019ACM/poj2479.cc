#include <bits/stdc++.h>
using namespace std;

const int SIZE = 50005;
int a[SIZE];
int l[SIZE], r[SIZE];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(a, 0, sizeof(a));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		int n;
		scanf("%d", &n);
		bool flag = false;
		int num = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if(a[i] >= 0) num++;
		}
		if(num <= 2) {
			sort(a, a+n);
			printf("%d\n", a[n-1]+a[n-2]);
			continue;
		}
		l[0] = a[0]<=0?0:a[0];
		for(int i = 1; i < n; i++) {
			if(a[i]+l[i-1] <= 0) {
				l[i] = 0;
			} else {
				l[i] = a[i]+l[i-1];
			}
		}
		for(int i = 1; i < n; i++) {
			l[i] = max(l[i], l[i-1]);
		}
		r[n-1] = a[n-1]<=0?0:a[n-1];
		for(int i = n-2; i >= 0; i--) {
			if(a[i]+r[i+1] <= 0) {
				r[i] = 0;
			} else {
				r[i] = a[i]+r[i+1];
			}
		}
		for(int i = n-2; i >= 0; i--) {
			r[i] = max(r[i], r[i+1]);
		}
		int ans = -0x3f3f3f3f;
		for(int i = 0; i < n-1; i++) {
			ans = max(ans, l[i]+r[i+1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
