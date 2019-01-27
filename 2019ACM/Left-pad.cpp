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

const int SIZE = 100005;
char str[SIZE];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	char mark;
	scanf("%d %c", &n, &mark);
	getchar();
	fgets(str, SIZE, stdin);
	int len = strlen(str);
	str[len-1] = '\0';
	len--;
	if(strlen(str) >= n) {
		for(int i = strlen(str)-n; i < strlen(str); i++) {
			printf("%c", str[i]);
		}
	} else {
		for(int i = 0; i < n-strlen(str); i++) {
			printf("%c", mark);
		}
		printf("%s", str);
	}
    return 0;
}
