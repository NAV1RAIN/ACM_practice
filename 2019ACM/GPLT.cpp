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

const int SIZE = 10010;
char str[SIZE];
int num[10];
char mark[10] = {'G', 'P', 'L', 'T'};
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%s", str)!=EOF) {
		int len = strlen(str);
		int jl = 0;
		for(int i = 0; i < len; i++) {
			if(str[i] == 'G' || str[i] == 'g') num[1]++;
			if(str[i] == 'P' || str[i] == 'p') num[2]++;
			if(str[i] == 'L' || str[i] == 'l') num[3]++;
			if(str[i] == 'T' || str[i] == 't') num[0]++;
			jl++;
		}
		for(int i = 1; i <= jl; i++) {
			if(i%4 == 1 && num[1] > 0) {
				printf("G");
				num[1]--;
			} else if(i%4 == 2 && num[2] > 0) {
				printf("P");
				num[2]--;
			} else if(i%4 == 3 && num[3] > 0) {
				printf("L");
				num[3]--;
			} else if(i%4 == 0 && num[0] > 0) {
				printf("T");
				num[0]--;
			} else if(num[1] == 0 && num[2] == 0 && num[3] == 0 && num[0] == 0) {
				break;
			} else if(num[i%4] == 0) {
				jl++;
			}
		}
	} 
    return 0;
}

