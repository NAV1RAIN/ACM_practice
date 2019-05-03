#include <cstdio>
using namespace std;
int c[100][100], w[100][100];
int jl[100];
int ans[100];
int answ = 0x3f3f3f3f;
int n, m, d;
void dfs(int x) {
	if(x > n) {
		int tc = 0, tw = 0;
		for(int i = 1; i <= n; i++) tc += c[i][jl[i]];
		if(tc <= d) {
			for(int i = 1; i <= n; i++) tw += w[i][jl[i]];
			if(tw < answ) {
				answ = tw;
				for(int i = 1; i <= n; i++) ans[i] = jl[i];
			}
		}
		return ;
	}
	for(int i = 1; i <= m; i++) {
		jl[x] = i;
		dfs(x+1);
	}

	return ;
}
int main() {
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	dfs(1);
	printf("%d\n", answ);
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
