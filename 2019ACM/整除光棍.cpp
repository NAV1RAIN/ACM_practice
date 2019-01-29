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

char ans[200];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x;
	scanf("%d", &x);
	int temp = 1;
	int len = 1;
	while(temp < x) {
		temp = temp*10+1;
		len++;
	}
	int bj = 0;
	while(true) {
		ans[bj++] = temp/x+'0';
		temp = temp%x;
		if(temp == 0) break;
		else {
			temp = temp*10+1;
			len++;
		}
	}
	printf("%s %d\n", ans, len);
    return 0;
}
