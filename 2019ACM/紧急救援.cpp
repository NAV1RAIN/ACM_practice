#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int n, m, s, d;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int arr[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN];
int num[MAXN];
int lowcost[MAXN];
int maxteam[MAXN];
void Dijkstra(int n, int beg) {
	memset(num, 0, sizeof(num));
	for(int i = 0; i < n; i++) {
		lowcost[i] = INF;
		maxteam[i] = 0;
		vis[i] = false;
		pre[i] = -1;
	}
	lowcost[beg] = 0;
	maxteam[s] = arr[s];
	num[s] = 1;
	for(int j = 0; j < n; j++) {
		int k = -1;
		int Min = INF;
		for(int i = 0; i < n; i++) {
			if(!vis[i] && lowcost[i] < Min) {
				Min = lowcost[i];
				k = i;
			}
		}
		if(k == -1) break;
		vis[k] = true;
		for(int i = 0; i < n; i++) {
			if(!vis[i] && lowcost[k]+cost[k][i] < lowcost[i]) {
				lowcost[i] = lowcost[k]+cost[k][i];
				maxteam[i] = maxteam[k]+arr[i];
				pre[i] = k;
				num[i] = num[k];
			} else if(!vis[i] && lowcost[k]+cost[k][i] == lowcost[i]) {
				num[i] = num[k]+num[i];
				if(maxteam[k]+arr[i] > maxteam[i]) {
					maxteam[i] = maxteam[k]+arr[i];
					pre[i] = k;
				}
			}
		}
	}
}
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	memset(cost, INF, sizeof(cost));
    scanf("%d%d%d%d", &n, &m, &s, &d);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		cost[a][b] = cost[b][a] = c;
	}
	Dijkstra(n, s);
	printf("%d %d\n", num[d], maxteam[d]);
	stack<int> que;
	int ss = d;
	que.push(d);
	while(pre[ss] != -1) {
		que.push(pre[ss]);
		ss = pre[ss];
	}
	printf("%d", que.top());
	que.pop();
	while(que.size()) {
		printf(" %d", que.top());
		que.pop();
	}
	printf("\n");
//	printf("%d\n", lowcost[d]);
//	for(int i = 0; i < n; i++) {
//		printf("%d ", pre[i]);
//	}
//	printf("\n%d\n", ans);
    return 0;
}
