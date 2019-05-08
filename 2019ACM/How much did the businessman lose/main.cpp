#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n, m, p, c;
    while(scanf("%d%d%d%d", &n, &m, &p, &c) != EOF) {
        if(!n && !m && !p && !c) break;
        printf("%d\n", n-m+p);
    }
    return 0;
}