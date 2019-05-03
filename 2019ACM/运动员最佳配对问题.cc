#include <cstdio>
using namespace std;
int n;
int p[100][100], q[100][100];
int jl[100];
bool ok[100];
int maxx = -0x3f3f3f3f;
void dfs(int x) {
	if(x > n) {
		int temp = 0;
		for(int i = 1; i <= n; i++) {
			temp += p[i][jl[i]]*q[jl[i]][i];
		}
		if(temp > maxx) maxx = temp;
	}
	for(int i = 1; i <= n; i++) {
		if(ok[i]) continue;
		jl[x] = i;
		ok[i] = true;
		dfs(x+1);
		ok[i] = false;
	}
	return ;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &q[i][j]);
		}
	}
	dfs(1);
	printf("%d\n", maxx);
	return 0;
}
