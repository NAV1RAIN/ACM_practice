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
int num[10];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int l, n;
	scanf("%d%d", &l, &n);
	int t = pow(26, l)-n;
	int hh = -1;
	int len = l-1;
	while(t != 0) {
		hh = t%26;
	    t /= 26;
		num[len--] = hh;
	}
	for(int i = 0; i < l; i++) {
		printf("%c", 'a'+num[i]);
	}
	printf("\n");
    return 0;
}
