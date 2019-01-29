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

int hh[105][105];
int zw[20000];
int num[105];
bool flag[105];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	memset(zw, -1, sizeof(zw));
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		num[i] *= 10;
	}
	int l = 0, r = 0;
	int jl = n, xb = 0;
	while(true) {
		if(num[r%n] > 0) {
			zw[l++] = r%n;
			num[r%n]--;
		} else if(num[r%n] == 0 && !flag[r%n]) {
			flag[r%n] = true;
			jl--;
		}
		r++;
		if(jl == 1) {
			for(int i = 0; i < n; i++) {
				if(num[i] > 0) {
					xb = i;
					if(zw[l-1] == xb) l++;
					break;
				}
			}
			break;
		}
	}
	for(int i = 0; i < num[xb]; i++) {
		zw[l+i*2] = xb;
	}
	l+=num[xb]*2;
	for(int i = 0; i < l; i++) {
		if(zw[i] == -1) continue;
		int temp = ++hh[zw[i]][0];
		hh[zw[i]][temp] = i+1;
	}
	for(int i = 0; i < n; i++) {
		printf("#%d\n", i+1);
		for(int j = 1; j <= hh[i][0]; j++) {
			printf("%s%d", j%10 == 1?"":" ", hh[i][j]);
			if(j%10 == 0) printf("\n");
		}
	}
    return 0;
}
