#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
struct state {
    int len, link;
    map<char, int> next;
    bool is_clon;
    int first_pos;
    vector<int> inv_link;
};
const int MAXLEN = 100005;
state st[MAXLEN * 2];
int sz, last;
void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
    /*
	// 若关于不同的字符串多次建立后缀自动机，就需要执行这些代码：
	for (int i=0; i<MAXLEN*2; ++i)
		st[i].next.clear();
	*/
}
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].first_pos = st[cur].len - 1;
    int p;
    for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p != -1 && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
vector<int> ans;
void output(int v, int P_leng) {
    if (!st[v].is_clon)
        cout << st[v].first_pos - P_leng + 1 << endl;
        ans.push_back(st[v].first_pos - P_leng + 1);
    for (size_t i = 0; i < st[v].inv_link.size(); ++i)
        output(st[v].inv_link[i], P_leng);
}
char str[MAXLEN];
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", str);
		printf("%s\n", str);
        int len = strlen(str);
        sa_init();
        for (int i = 0; i < len; i++) {
            sa_extend(str[i]);
        }
        for (int v = 1; v < sz; v++) {
            st[st[v].link].inv_link.push_back(v);
        }
        int l, r, k;
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &l, &r, &k);
            output(3,1);
            int ttl = l-1;
            int ttt = r-l+1;
            ans.clear();
            int lll = ans.size();
            printf("\n%d\n\n", lll);
        }
    }
    return 0;
}
