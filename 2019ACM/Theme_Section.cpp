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
const int SIZE = 1e6+5;
char str[SIZE];
int Next[SIZE];
void kmp_pre() {
	int i, j;
	j = Next[0] = -1;
	i = 0;
	int m = strlen(str);
	while(i < m) {
		while(j != -1 && str[i] != str[j]) j = Next[j];
		Next[++i] = ++j;
	}
}
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", str);
		kmp_pre();
		int m = strlen(str);
		bool flag = false;
		if(Next[m] == m-1) flag = true;
		if(!flag) printf("%d\n", Next[m]);
		else if(m == 1) printf("1\n");
		else printf("%d\n", m/2);
	}
    return 0;
}
