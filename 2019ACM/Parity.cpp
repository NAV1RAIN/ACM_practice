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
    int even, odd;
	int b, k;
	int temp;
	even = odd = 0;
	scanf("%d%d", &b, &k);
	for(int i = 0; i < k-1; i++) {
		scanf("%d", &temp);
		if(temp&1) odd++;
		else even++;
	}
	scanf("%d", &temp);
	bool flag = true;
	if(b&1 && odd&1) {
		flag = false;
	}
	if(temp&1) {
		printf(flag?"odd\n":"even\n");
	} else {
		printf(flag?"even\n":"odd\n");
	}
	return 0;
}
