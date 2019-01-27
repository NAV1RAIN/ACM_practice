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

struct node {
	char name[10];
	int sex;
	bool mark = false;
}stu[100];
int main(int argc, const char *argv[])
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %s", &stu[i].sex, &stu[i].name);
	}
	int hh = 0;
	for(int i = 0; i < n && hh != n/2; i++) {
		if(!stu[i].mark) {
			for(int j = n-1; j >= 0; j--) {
				if(stu[i].sex != stu[j].sex && !stu[j].mark) {
					stu[i].mark = stu[j].mark = true;
					hh++;
					if(i > j) printf("%s %s\n", stu[i].name, stu[j].name);
					else printf("%s %s\n", stu[i].name, stu[j].name);
					break;
				}
			}
		}
	}
    return 0;
}
