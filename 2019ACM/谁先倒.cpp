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
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int jial, yil;
	scanf("%d%d", &jial, &yil);
	int jiajl, yijl;
	jiajl = yijl = 0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int ja, jb, ya, yb;
		scanf("%d%d%d%d", &ja, &jb, &ya, &yb);
		if(jb == yb) continue;
		if(ja+ya == jb) jiajl++;
		if(ja+ya == yb) yijl++;
		if(jiajl > jial) {
			printf("A\n%d", yijl);
			break;
		}
		if(yijl > yil) {
			printf("B\n%d", jiajl);
			break;
		}
	}
    return 0;
}
