#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
struct node {
	double a, b;
}ss[SIZE];
bool cmp1(const node& a, const node& b) {
	return a.a > b.a;
}
bool cmp2(const node& a, const node& b) {
	return a.b > b.b;
}
bool cmp3(const node& a, const node& b) {
	return a.b < b.b;
}
node s1[SIZE], s2[SIZE], s3[SIZE];
int l1, l2, l3;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf%lf", &ss[i].a, &ss[i].b);
		if(ss[i].a > ss[i].b) s1[l1++] = ss[i];
		else if(ss[i].a < ss[i].b) s2[l2++] = ss[i];
		else s3[l3++] = ss[i];
	}
	long long ans = 0;
	sort(s1, s1+l1, cmp1);
	sort(s2, s2+l2, cmp2);
	for(int i = 0; i < l1; i++) {
		ans += s1[i].a*i+s1[i].b*(n-i-1);
	}
	for(int i = 0; i < l2; i++) {
		ans += s2[i].b*i+s2[i].a*(n-i-1);
	}
	for(int i = 0; i < l3; i++) {
		ans += s3[i].a*(n-1);
	}
	cout << ans << '\n';
	return 0;
}
