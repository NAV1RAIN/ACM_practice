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

const int SIZE = 50010;
void pre_EKMP(char x[], int m, int NEXT[]) {
	NEXT[0] = m;
	int j = 0;
	while(j + 1 < m && x[j] == x[j+1]) j++;
	NEXT[1] = j;
	int k = 1;
	for(int i = 2; i < m; i++) {
		int p = NEXT[k] + k - 1;
		int L = NEXT[i-k];
		if(i+L < p+1) NEXT[i] = L;
		else {
			j = max(0, p-i+1);
			while(i+j < m&& x[i+j] == x[j]) j++;
			NEXT[i] = j;
			k = i;
		}
	}
}
void EKMP(char x[], int m, char y[], int n, int NEXT[], int extend[]) {
	pre_EKMP(x, m, NEXT);
	int j = 0;
	while(j < n && j < m && x[j] == y[j]) j++;
	extend[0] = j;
	int k = 0;
	for(int i = 1; i < n; i++) {
		int p = extend[k]+k-1;
		int L = NEXT[i-k];
		if(i+L < p+1) extend[i] = L;
		else {
			j = max(0, p-i+1);
			while(i+j < n && j < m && y[i+j] == x[j]) j++;
			extend[i] = j;
			k = i;
		}
	}
}
char str1[SIZE];
char str2[SIZE];
int NEXT[SIZE];
int extend[SIZE];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s", str1) != EOF) {
		scanf("%s", str2);
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		EKMP(str1, len1, str2, len2, NEXT, extend);
		int xbjl = 0;
		int ans = 0;
		for(int i = 1; i <= len2; i++) {
			if(extend[i] > ans) {
				xbjl = i;
				ans = extend[i];
			}
		}
		if(ans == 0) printf("0\n");
		else {
			for(int i = 0; i < ans; i++) {
				printf("%c", str1[i]);
			}
			printf(" %d\n", ans);
		}
	}
    return 0;
}
