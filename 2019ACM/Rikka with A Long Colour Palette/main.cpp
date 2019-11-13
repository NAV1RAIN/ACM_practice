#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5+5;
struct Node {
    int zhi, id, val;
    Node() {}
    Node(int _zhi, int _val) { zhi = _zhi, id = -1, val = _val; }
} node[(SIZE << 1) + 5];
bool cmp(const Node& a, const Node& b) {
    return a.zhi < b.zhi;
}
vector<int> bj;
int panel[SIZE];
int qj[SIZE];
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        bj.clear();
        memset(qj, 0, sizeof(qj));
        int n, k;
        scanf("%d%d", &n, &k);
        int len = n << 1;
        for(int i = 0; i < n; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            node[i << 1] = Node(l, 1);
            node[i << 1 | 1] = Node(r, -1);
            bj.push_back(l);
            bj.push_back(r);
        }
        sort(bj.begin(), bj.end());
        int sLen = unique(bj.begin(), bj.end()) - bj.begin();
        for(int i = 0; i < len; i++) {
            int hh = lower_bound(bj.begin(), bj.end(), node[i].zhi) - bj.begin();
            qj[hh] = node[i].zhi;
            node[i].id = hh;
            panel[hh] = node[i].val;
        }
        for(int i = 1; i < sLen; i++) {
            panel[i] += panel[i-1];
        }
        bool flag = false;
        int jl = -1;
        int length = 0;
        for(int i = 0; i < sLen; i++) {
            if(panel[i] >= k) {
                if(flag) {
                    length += qj[i] - qj[jl];
                    printf("%d %d\n", qj[i], qj[jl]);
                }
                flag = true;
                jl = i;
            } else {
                flag = false;
                jl = -1;
            }
        }
        printf("%d\n", length + 1);
    }
    return 0;
}