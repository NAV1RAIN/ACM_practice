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

typedef unsigned int uu;
bool primeJudge(uu hh) {
	if(hh == 1) return true;
	if(hh == 2) return false;
	for(uu j = 2; j <= sqrt(hh); j++) {
		if(hh%j == 0) {
			return true;
		}
	}
	return false;
}
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	scanf("%d", &n);
	while(n--) {
		uu temp;
		scanf("%u", &temp);
		if(primeJudge(temp)) puts("No");
		else puts("Yes");
	}
    return 0;
}
