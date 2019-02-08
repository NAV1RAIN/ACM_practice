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

const int SIZE = 1e5+5;
int arr[SIZE];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int temp;
	scanf("%d", &temp);
	for(int i = 1; i < n; i++) {
		int hh;
		scanf("%d", &hh);
		arr[i] = hh-temp;
		temp = hh;
	}
	sort(arr+1, arr+n);
	int ans = k;
	for(int i = 1; i <= n-k; i++) {
		ans += arr[i];
	}
	printf("%d\n", ans);
    return 0;
}
