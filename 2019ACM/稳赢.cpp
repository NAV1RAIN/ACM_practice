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

int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, len = 0;
	scanf("%d", &n);
	char str[20];
	while(scanf("%s", &str) && strcmp(str, "End")) {
		if(len%(n+1) == n) printf("%s\n", str);
		else if(!strcmp(str, "ChuiZi")) printf("Bu\n");
		else if(!strcmp(str, "JianDao")) printf("ChuiZi\n");
		else if(!strcmp(str, "Bu")) printf("JianDao\n");
		len++;
	}
    return 0;
}
