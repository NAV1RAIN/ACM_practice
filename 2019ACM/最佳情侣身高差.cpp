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
	getchar();
	for(int i = 0; i < n; i++) {
		char sex;
		double h;
		scanf("%c %lf", &sex, &h);
		if(sex == 'M') printf("%.2f\n", h/1.09);
		else printf("%.2f\n", h*1.09);
		getchar();
	}
    return 0;
}
