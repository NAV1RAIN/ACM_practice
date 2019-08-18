#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 1e4;
char str[SIZE];
vector<int> ss;
int main() {
	// freopen("RAW/in", "r", stdin);
	freopen("RAW/out", "w", stdout);
	ss.push_back(1);
	ss.push_back(1);
	long long ans = 1;
	for(int i = 3; i < 1000; i++) {
		int jj = 1;
		ans = 0;
		for(auto it = ss.begin(); it != ss.end(); it++) {
			ans += (*it)*jj;
			jj++;
		}
		ss.push_back(ans%i);
		printf("%lld\n", ans%i);
	}
	return 0;
}
