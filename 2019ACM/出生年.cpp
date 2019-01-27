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
    int y, n;
	bool arr[20] = {0};
	int flag = 0;
	scanf("%d%d", &y, &n);
	for(int i = y; i <= 4000 && flag == 0; i++) {
		int sum = 0;
		arr[i/1000] = true;
		arr[i/100%10] = true;
		arr[i/10%10] = true;
		arr[i%10] = true;
		for(int j = 0; j < 10; j++) {
			if(arr[j] == true) sum++;
		}
		if(sum == n) flag = i;
		else memset(arr, 0, sizeof(arr));
	}
	printf("%d %04d", flag-y, flag);
    return 0;
}
