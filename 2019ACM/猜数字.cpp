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

char str[10005][10];
int arr[10005];
int main() {
  int n;
  scanf("%d", &n);
  double tt = 0;
  for(int i = 0; i < n; i++) {
    scanf("%s %d", &str[i], &arr[i]);
    tt += arr[i];
  }
  int xb = 1000000;
  int min = 1000000;
  tt = tt*1.0/n/2;
  for(int i = 0; i < n; i++) {
    if(fabs(tt-arr[i]) < min) {
      xb = i;
    }
  }
  printf("%.0f %s\n", tt, str[xb]);
  return 0;
}
