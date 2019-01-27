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

char tel[20];
int num[20];
int mark[20];
bool cmp(const int& a, const int& b) {
	return a > b;
}
int main(int argc, const char *argv[])
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
	memset(num, -1, sizeof(num));
    scanf("%s", &tel);
	for(int i = 0; tel[i] != '\0'; i++) {
		num[tel[i]-'0'] = tel[i]-'0';
	}
	sort(num, num+10, cmp);
	int hh = 0;
	for(int i = 0; tel[i] != '\0'; i++) {
		for(int j = 0; j < 10; j++) {
			if(num[j] == tel[i]-'0') {
				mark[hh++] = j;
				break;
			}
		}
	}
	printf("int[] arr = new int[]{");
	printf("%d", num[0]);
	for(int i = 1; num[i] != -1; i++) {
		printf(",%d", num[i]);
	}
	printf("};\nint[] index = new int[]{%d", mark[0]);
	for(int i = 1; i < hh; i++) {
		printf(",%d", mark[i]);
	}
	printf("};\n");
    return 0;
}
