#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5005;
int dp[SIZE*SIZE];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int w, v;
		scanf("%d%d", &w, &v);
		for(int j = m; j > 0; j--) {
			if(w <= j) dp[j] = max(dp[j], dp[j-w] + v);
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}
