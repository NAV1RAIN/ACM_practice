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
typedef long long LL;
const int SIZE = 5e4+5;
struct Node {
	int u, v;
	LL w;
} arr[SIZE];
int main() {
    freopen("RAW/in","r",stdin);
    freopen("RAW/out","w",stdout);
    int t;
	scanf("%d", &t);
	while(t--) {
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%lld", &arr[i].u, &arr[i].v, &arr[i].w);
		}
	}
    return 0;
}
