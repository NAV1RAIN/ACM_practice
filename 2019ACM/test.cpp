#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int SIZE = 1e5+5;
int arr[SIZE];
long long jc[SIZE];
struct Node{
	int num;
	string ss;
} node[SIZE];
bool cmp(const Node& a, const Node& b) {
	if(a.num != b.num) return a.num < b.num;
	else return a.ss < b.ss;
}
int main() {
	freopen("output", "w", stdout);
	jc[1] = 1;
	for(int i = 2; i <= SIZE-5; i++) {
		jc[i] = jc[i]*jc[i-1]%MOD;
	}
	for(int i = 3; i <= 10; i++) {
		for(int j = 0; j < i; j++) {
			arr[j] = j+1;
		}
		vector<string> lie;
		lie.clear();
		int num[SIZE] = {0};
		do {
			string ss = "0";
			// for(int k = 0; k < i; k++) {
			// 	printf("%d ", arr[k]);
			// }
			// printf("-- 0");
			for(int k = 1; k < i; k++) {
				int maxn = -1;
				int minn = 0x3f3f3f3f;
				for(int kk = 0; kk <= k; kk++) {
					maxn = max(maxn, arr[kk]);
					minn = min(minn, arr[kk]);
				}
				ss.push_back('0'+(maxn-minn));
				// printf(" %d", maxn-minn);
			}
			bool flag = false;
			for(auto it = lie.begin(); it != lie.end(); it++) {
				if(ss == (*it)) {
					num[it-lie.begin()]++;
					flag = true;
					break;
				}
			}
			if(!flag) {
				num[lie.end()-lie.begin()] = 1;
				lie.push_back(ss);
			}
			// printf("\n");
		} while(next_permutation(arr, arr+i));
		for(auto it = lie.begin(); it != lie.end(); it++) {
			node[it-lie.begin()].num = num[it-lie.begin()];
			node[it-lie.begin()].ss = (*it);
			// cout << (*it) << " --- " << num[it-lie.begin()] << '\n';
		}
		sort(node, node+lie.size(), cmp);
		for(int i = 0; i < lie.size(); i++) {
			cout << node[i].ss << " --- " << node[i].num << '\n';
		}
		cout << "\n\n";
	}
	return 0;
}