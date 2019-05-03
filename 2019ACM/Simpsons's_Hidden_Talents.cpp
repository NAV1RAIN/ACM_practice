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

const int SIZE = 5e4+5;
char s1[SIZE], s2[SIZE];
int Next[SIZE], ex[SIZE];
void kmp_pre() {
	int i, j;
	int m = strlen(s1);
	j = Next[0] = -1;
	i = 0;
	while(i < m) {
		while(j != -1 && s1[i] != s1[j]) j = Next[j];
		Next[++i] = ++j;
	}
}
void kmp_ex() {
	int i, j;
	int m = strlen(s2);
	j = ex[0] = -1;
	i = 0;
	while(i < m) {
		while(j != -1 && s1[j] != s2[i]) j = ex[j];
		ex[++i] = ++j;
	}
}
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(scanf("%s%s", &s1, &s2) != EOF) {
		kmp_pre();
		kmp_ex();
		int hh = strlen(s2);
		if(ex[hh] == 0) printf("0\n");
		else {
			for(int i = 0; i < ex[hh]; i++) {
				printf("%c", s1[i]);
			}
			printf(" %d\n", ex[hh]);
		}
	}
	return 0;
}
