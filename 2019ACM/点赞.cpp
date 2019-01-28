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

bool cmp(const int &a, const int &b) {
	return a > b;
}
int mark[1005];
int arr[1005];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	int max = 0;
	int len = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++) {
			int temp;
			scanf("%d", &temp);
			mark[temp]++;
		}
	}
	for(int i = 0; i < 1005; i++) {
		if(mark[i] > max) {
			max = mark[i];
			memset(arr, 0, sizeof(arr));
			len = 0;
			arr[len++] = i;
		} else if(mark[i] == max) {
			arr[len++] = i;
		}
	}
	sort(arr, arr+len, cmp);
	printf("%d %d\n", arr[0], max);
    return 0;
}
