#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int  SIZE = 14000;
int dp[SIZE];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int w, v;
		scanf("%d%d", &w, &v);
		for(int j = m; j >= w; j--) {
			dp[j] = max(dp[j], dp[j-w]+v);
		}
	}
	printf("%d\n", dp[m]);
    return 0;
}
