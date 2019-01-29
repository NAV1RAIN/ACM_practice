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
char pic[105][105];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char mark;
	int n;
	scanf("%c %d", &mark, &n);
	getchar();
	bool flag = true;
	for(int i = 0; i < n; i++) gets(pic[i]);
	for(int i = 0; i < n && flag; i++) {
		for(int j = 0; j < n && flag; j++) {
			if(pic[i][j] != pic[n-i-1][n-j-1]) flag = false;
		}
	}
	printf("%s", flag?"bu yong dao le\n":"");
	for(int i = n-1; i >= 0; i--) {
		for(int j = n-1; j >= 0; j--) {
			printf("%c", pic[i][j]!=' '?mark:' ');
		}
		printf("\n");
	}
    return 0;
}
