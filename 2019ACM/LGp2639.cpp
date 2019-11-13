#include <bits/stdc++.h>
using namespace std;

const int SIZE = 50000;
int S[SIZE];
int dp[SIZE];
int main() {
	int h, n;
	scanf("%d%d", &h, &n);
	for(int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		for(int j = h; j >= t; j--) {
			dp[j] = max(dp[j], dp[j-t]+t);
			//if(dp[j-1]+t <= h && dp[j-1]+t > dp[j]) dp[j] = dp[j-1]+t;
		}
	}
	
	printf("%d\n", dp[h]);
	return 0;
}
