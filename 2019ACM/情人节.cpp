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

char str[1000][20];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int len = 0;
	while(scanf("%s", &str[len]) && strcmp(str[len], ".")) len++;
	if(len < 2) printf("Momo... No one is for you ...\n");
	else if(len > 14) printf("%s and %s are inviting you to dinner...\n", str[1], str[13]);
	else printf("%s is the only one for you...\n", str[1]);
    return 0;
}
