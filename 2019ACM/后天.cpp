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
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int n;
	scanf("%d", &n);
	n += 2;
	if(n%7 == 0) n = 7;
	else n%=7;
	printf("%d", n);
    return 0;
}
