#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
struct Node {
    string str;
    int p, t;
} arr[SIZE];
bool cmp(const Node& a, const Node& b) {
    if(a.p != b.p) return a.p > b.p;
    else return a.t < b.t;
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, d;
        cin >> n >> d;
        for(int i = 0; i < n; i++) {
            cin >> arr[i].str >> arr[i].p >> arr[i].t;
        }
        sort(arr, arr + n, cmp);
        int t1 = n*d%10;
        int t2 = n*d/10;
        if(t1 != 5) {
            cout << "Quailty is very great" << '\n';
        } else {
            cout << arr[t2].str << '\n';
        }
    }
    return 0;
}