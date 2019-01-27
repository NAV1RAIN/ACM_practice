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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
	int ji, ou;
	ji = ou = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(temp%2 == 0) ou++;
		else ji++;
	}
	printf("%d %d", ji, ou);
    return 0;
}
