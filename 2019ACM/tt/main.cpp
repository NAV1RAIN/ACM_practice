#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5e5+50;
struct Node{
    int val;
    int start;
    int end;
};
vector<Node> v;
vector<long long> inc;
int s[SIZE];
int len = 0;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i <n; i++) {
		scanf("%lld", &v[i].val);
		if(i == 0) inc[i] = v[i].val;
		else inc[i] = inc[i-1]+v[i].val;
		v[i].start = i;
		v[i].end = i;
	}
	int i = 0;
	memset(s, 0, sizeof(s));
	len = 0;
	while(i < (int)v.size()) {
		if(len == 0 || v[i].val > v[s[len-1]].val) {
			s[len++] = i++;
		} else {
			v[i].start = v[s[len-1]].start;
			s[--len] = 0;
		}
	}
	memset(s, 0, sizeof(s));
	i = n-1;
	len = 0;
	while(i >= 0) {
		if(len == 0 || v[i].val > v[s[len-1]].val) {
			s[len++] = i--;
		} else {
			v[i].start = v[s[len-1]].start;
			s[--len] = 0;
		}
	}
	long long ans = 0;
	int istart = 0, iend = 0;
	for(int i = 0; i < n; i++) {
		long long cans = v[i].val*(inc[v[i].end]-inc[v[i].start-1]);
		if(cans > ans) {
			ans = cans;
			istart = v[i].start;
			iend = v[i].end;
		}
	}
	cout << ans << '\n';

	return 0;
}
