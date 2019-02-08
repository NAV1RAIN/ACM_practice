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

char matrix[1005][1005];
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", &matrix[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == 'X' && i-1>=0 && j-1>=0 && matrix[i-1][j-1] == 'X' && j+1<n && i+1<n && matrix[i-1][j+1]=='X' && matrix[i+1][j-1]=='X' && matrix[i+1][j+1]=='X') ans++;
		}
	}
	printf("%d\n", ans);
    return 0;
}
