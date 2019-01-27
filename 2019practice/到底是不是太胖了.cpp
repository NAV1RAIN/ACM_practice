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
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		double height, weight;
		scanf("%lf%lf", &height, &weight);
		double bz = (height-100)*0.9*2;
		if(fabs(weight-bz) < 0.1*bz) printf("You are wan mei!\n");
		else if((weight-bz) > 0) printf("You are tai pang le!\n");
		else printf("You are tai shou le!\n");
	}
    return 0;
}
