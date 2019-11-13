#include <bits/stdc++.h>
using namespace std;

int arr[15][15];
void pre() {
	for(int i = 1; i <= 10; i++) {
		arr[1][i] = 1;
		arr[i][1] = 1;
	}
	for(int i = 2; i <= 10; i++) {
		for(int j = 2; j <= 10; j++) {
			arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pre();
	printf("%d\n", arr[n][n]);
	return 0;
}
