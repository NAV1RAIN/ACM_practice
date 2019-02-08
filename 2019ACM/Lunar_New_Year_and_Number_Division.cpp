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

int arr[300005];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	unsigned long long ans = 0;
	for(int i = 0; i < n/2; i++) {
		ans += (arr[i]+arr[n-i-1])*(arr[i]+arr[n-i-1]);
	}
	printf("%llu\n", ans);
    return 0;
}
