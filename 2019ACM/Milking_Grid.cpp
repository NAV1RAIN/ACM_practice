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

char pic[10010][100];
int rNext[10010], cNext[10010];
bool cmp_r(int x, int y, int c) {
	for(int i = 0; i < c; i++) {
		if(pic[x][i] != pic[y][i]) return false;
	}
	return true;
}
bool cmp_c(int x, int y, int r) {
	for(int i = 0; i < r; i++) {
		if(pic[i][x] != pic[i][y]) return false;
	}
	return true;
}
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int r, c;
	scanf("%d%d", &r, &c);
	for(int i = 0; i < r; i++) scanf("%s", pic[i]);
	int i, j;
	j = rNext[0] = -1;
	i = 0;
	while(i < r) {
		while(j != -1 && !cmp_r(i, j, c)) j = rNext[j];
		rNext[++i] = ++j;
	}
	int ans1 = r-rNext[r];
	j = cNext[0] = -1;
	i = 0;
	while(i < c) {
		while(j != -1 && !cmp_c(i, j, r)) j = cNext[j];
		cNext[++i] = ++j;
	}
	int ans2 = c-cNext[c];
	printf("%d\n", ans1*ans2);
    return 0;
}
