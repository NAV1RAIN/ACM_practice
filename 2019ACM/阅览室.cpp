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

const int SIZE = 1005;
struct node{
	int ks;
	int sj;
	node(){ks = -1, sj = -1;}
} arr[SIZE];

int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int Days, daysjl = 0;
	int temp;
	int num = 0, time = 0;
	scanf("%d", &Days);
	while(scanf("%d", &temp) != EOF) {
		getchar();
		char zt;
		int hh, mm;
		zt = getchar();
		scanf("%d:%d", &hh, &mm);
		if(temp == 0) {
			daysjl++;
			if(num != 0) printf("%d %d\n", num, (int)(time*1.0/num+0.5));
			else printf("0 0\n");
			num = time = 0;
			memset(arr, -1, sizeof(arr));
		}
		if(daysjl == Days) break;
		if(temp == 0) continue;
		if(zt == 'S') {
			arr[temp].ks = hh*60+mm;
		} else {
			if(arr[temp].ks != -1 || arr[temp].sj != -1) {
				num++;
				arr[temp].sj = hh*60+mm-arr[temp].ks;
				//printf("%d %d\n", hh*60+mm, arr[temp].ks);
				time+=arr[temp].sj;
				arr[temp].ks = arr[temp].sj = -1;
			}
		}
	}
    return 0;
}
