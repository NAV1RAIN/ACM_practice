#include <bits/stdc++.h>
using namespace std;

vector<int> ss;
bool isprime[500];
int main() {
	freopen("out", "w", stdout);
	for(int i = 2; i <= 200; i++) {
		bool flag = false;
		for(int j = 2; j <= sqrt(i); j++) {
			if(i%j == 0) {
				flag = true;
			}
		}
		if(!flag) {
			ss.push_back(i);
			isprime[i] = true;
		}
	}
	int len = ss.size();
	for(int i = 5; i <= 100; i++) {
		bool flag = false;
		for(int j = 0; j < len; j++) {
			if(i-ss[j] > 1 && !isprime[i - ss[j]]) {
				printf("%d %d %d\n", i,  ss[j], i-ss[j]);
				flag = true;
				break;
			}
		}
		if(!flag) printf("%d -1\n", i);
	}
	return 0;
}
