#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5+5;
int x[SIZE];
int xb[SIZE];
int lr[SIZE][2];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int num = 0;
	for(int i = 1; i <= k; i++) {
		scanf("%d", &x[i]);
		if(xb[x[i]] == 0) num++;
		xb[x[i]] = max(xb[x[i]], i);
	}
	int ans = 2*(n-1)+n-num;
	for(int i = 1; i <= k; i++) {
		if(i < xb[x[i]-1] && !lr[x[i]][0]) lr[x[i]][0] = true, ans--;
		if(i < xb[x[i]+1] && !lr[x[i]][1]) lr[x[i]][1] = true, ans--;
	}
	printf("%d\n", ans);
	return 0;
}
