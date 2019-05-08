#include <bits/stdc++.h>
using namespace std;
const int MAXN = 0x3f3f3f3f;
const int SIZE = 1e5+5;
int x[SIZE];
int flag[SIZE];
int ok[SIZE];
int jl[SIZE];
int main() {
	int n, k;
	int num = 0;
	memset(flag, MAXN, sizeof(flag));
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++) {
		scanf("%d", &x[i]);
		if(x[i] == 1 || x[i] == n) jl[x[i]] = 1;
	   	else jl[x[i]] = 2;
		if(flag[x[i]] == MAXN) num++;
		flag[x[i]] = min(flag[x[i]], i);
		ok[x[i]] = max(ok[x[i]], i);
	}
	for(int i = 0; i < SIZE; i++) {
		if(flag[i] == MAXN) flag[i] = 0;
	}
	int ans = 2*(n-1)+n-num;
	for(int i = 1; i < k; i++) {
		if(x[i] == 1 && (i < flag[2] || i < ok[2]) && jl[x[i]]) ans--, jl[x[i]]--;
		else if(x[i] == n && (i < flag[n-1] || i < ok[n-1]) && jl[x[i]]) ans--, jl[x[i]]--;
		else if(x[i] != 1 && x[i] != n) {
			if((i < flag[x[i]-1] || i < ok[x[i]-1]) && jl[x[i]]) ans--, jl[x[i]]--;
			if((i < flag[x[i]+1] || i < ok[x[i]+1]) && jl[x[i]]) ans--, jl[x[i]]--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
