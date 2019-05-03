#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5+5;
char str[SIZE];
int arr[SIZE];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int num = 0;
	int hh = n-11;
	if(str[0] == '8') arr[0] = 1;
	else arr[0] = -1;
	for(int i = 1; i < n; i++) {
		if(str[i] == '8') arr[i] = arr[i-1]+1;
		else arr[i] = arr[i-1]-1;
	}
	if(arr[hh] > 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
