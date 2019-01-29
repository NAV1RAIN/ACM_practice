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
    int a, b;
	scanf("%d%d", &a, &b);
	printf("%d/", a);
	if(b >= 0) printf("%d=", b);
	else printf("(%d)=", b);
	if(b == 0) printf("Error\n");
	else printf("%.2f\n", a*1.0/b);
    return 0;
}
