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
	int bz = 12*60;
	int hh, mm;
    scanf("%d:%d", &hh, &mm);
	int minutes = hh*60+mm;
	if(minutes > bz) {
		char str[6] = "Dang";
		int dd = hh-12 + (mm == 0?0:1);
		for(int i = 0; i < dd; i++) {
			printf("%s", str);
		}
	} else {
		printf("Only %02d:%02d.  Too early to Dang.", hh, mm);	
	}
    return 0;
}
