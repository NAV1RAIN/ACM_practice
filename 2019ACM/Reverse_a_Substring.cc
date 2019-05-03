#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3e5+5;
char str[SIZE];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int maxx = (int)str[n-1];
	bool flag = false;
	int jl1, jl2;
	for(int i = 1; i < n; i++) {
		if(str[i] >= str[i-1]) flag = false;
		else {
			flag = true;
			jl1 = i, jl2 = i+1;
			break;
		}
	}
	if(flag) printf("YES\n%d %d\n", jl1, jl2);
	else printf("NO\n");
	return 0;
}
