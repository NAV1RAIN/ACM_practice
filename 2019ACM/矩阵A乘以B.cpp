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
int mxa[105][105];
int mxb[105][105];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ra, ca, rb, cb;
	scanf("%d%d", &ra, &ca);
	for(int i = 0; i < ra; i++) {
		for(int j = 0; j < ca; j++) {
			scanf("%d", &mxa[i][j]);
		}
	}
	scanf("%d%d", &rb, &cb);
	for(int i = 0; i < rb; i++) {
		for(int j = 0; j < cb; j++) {
			scanf("%d", &mxb[i][j]);
		}
	}
	if(ca != rb) printf("Error: %d != %d\n", ca, rb);
	else {
		printf("%d %d\n", ra, cb);
		for(int i = 0; i < ra; i++) {
			for(int j = 0; j < cb; j++) {
				int ans = 0;
				for(int h = 0; h < rb; h++) {
					ans += mxa[i][h]*mxb[h][j];
				}
				if(j == 0) printf("%d", ans);
				else printf(" %d", ans);
			}
			printf("\n");
		}
	}
    return 0;
}
