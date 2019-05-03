#include <cstdio>
bool dfs(int x, int n, int c, int arr[], bool flag[]) {
	if(x >= n) return false;
	int temp = 0;
	for(int i = 0; i < n; i++) {
		if(flag[i]) temp+=arr[i];
	}
	if(temp == c) {
		for(int i = 0; i < n; i++) {
			if(flag[i]) printf("%d ", arr[i]);
		}
		printf("\n");
		return true;
	}
	flag[x] = true;
	bool ok = dfs(x+1, n, c, arr, flag);
	if(ok) return true;
	flag[x] = false;
	ok = dfs(x+1, n, c, arr, flag);

	return ok;
}
int main() {
	int n, c;
	int arr[100] = {0};
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	bool flag[100] = {0};
	bool ok = dfs(0, n, c, arr, flag);
	if(!ok) printf("No Solution!\n");
	return 0;
}
