#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
int arr[SIZE];
set<int> st;
int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		st.clear();
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int jl = 0;
		for(int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			if(temp-arr[i] != 0) st.insert(temp-arr[i]);
			if(temp-arr[i] < 0) jl = 100;
		}
		jl += st.size();
		if(jl <= 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
