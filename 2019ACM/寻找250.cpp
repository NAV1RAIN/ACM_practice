#include <stdio.h>
int main() {
  int temp;
  int len = 0;
  while(scanf("%d", &temp) && temp != 250) len++;
  printf("%d\n", len+1);
}
