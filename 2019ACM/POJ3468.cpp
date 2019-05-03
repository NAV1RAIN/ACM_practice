/************************
* POJ-3468
* 给q个数，分别为A1,A2```AQ，还有两种操作
* C代表a到b区间全部加c
* Q表示查询a到b区间的和
* writted by SongZiqi
************************/
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

const int MAXN = 1e5+5;
int num[MAXN];
struct node {
	int l, r;
	long long nSum;
}segTree[MAXN<<2];
void Build(int i, int l, int r) {
	segTree[i].l = l;
	segTree[i].r = r;
	if(l == r) {
		segTree[i].nSum = num[l];
		return ;
	}
	int mid = (l + r) >> 1;
	Build(i << 1, l, mid);
	Build(i << 1 | 1, , mid+1, r);
	segTree[i].nSum = segTree[i << 1].nSum + segTree[i << 1 | 1].nSum;
}
void Add(int i, int t, int b) {
	segTree[i].nSum += b;
	if(segTree[i].l == t && segTree[i].r == t) return ;
	int mid = (segTree[i].l + segTree[i].r >> 1;
	if(t <= mid) Add(i << 1, t, b);
	else Add(i << 1 | 1, t, b);
}
int main(int argc, const char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    return 0;
}
