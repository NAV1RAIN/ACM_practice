#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int tmax = 1e5 + 5;
struct question {
    int kind, index;
    string s;
};
question data[tmax];
struct AC {
    int num, ch[6 * tmax][30], f[6 * tmax], last[6 * tmax], val[6 * tmax];
    int times[6 * tmax][2], dep[7 * tmax], pos[6 * tmax];
    vector<int> ans[6 * tmax];
    void init() {
        num = 0;
        memset(ch, 0, sizeof(ch));
        memset(f, 0, sizeof(f));
        memset(last, 0, sizeof(last));
        memset(val, 0, sizeof(val));
        memset(times, 0, sizeof(times));
        memset(dep, 0, sizeof(dep));
        memset(pos, -1, sizeof(pos));
        for (int i = 0; i < 6 * tmax; i++) {
            ans[i].clear();
        }
        return;
    }
    void insert(string s, int qN) {
        int u = 0, len = s.size(), id;
        for (int i = 0; i < len; i++) {
            id = s[i] - 'a';
            if (!ch[u][id]) ch[u][id] = ++num;
            u = ch[u][id];
        }
        val[u] = 1;
        dep[u] = len;
        data[qN].index = u;
        return;
    }
    void getfail() {
        queue<int> Q;
        Q.push(0);
        int x, u, v;
        while (!Q.empty()) {
            x = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++) {
                u = ch[x][i];
                if (!u) {
                    ch[x][i] = ch[f[x]][i];
                    continue;
                }
                Q.push(u);
                if (x == 0) continue;
                v = f[x];
                while (v && !ch[v][i]) v = f[v];
                f[u] = ch[v][i];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
        return;
    }
    void find(char *s) {
        memset(times, 0, sizeof(times));
        int len = strlen(s), u = 0, id, j;
        for (int i = 0; i < len; i++) {
            id = s[i] - 'a';
            u = ch[u][id];
            j = u;
            do {
                times[j][0]++;
                ans[j].push_back(i);
                if (i - pos[j] >= dep[j]) {
                    times[j][1]++;
                    pos[j] = i;
                }
                j = last[j];
            } while (j);
        }
        return;
    }
} ac;
char s[tmax];
char s11[tmax];
int qq[tmax];
int llen[tmax];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    // ios::sync_with_stdio(false);
    int q, kase = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        cin >> n >> q;
        cin >> s;
        ac.init();
        for (int i = 1; i <= q; i++) {
            int lll, rrr;
            scanf("%d%d%d", &lll, &rrr, &qq[i]);
            llen[i] = rrr-lll;
            sscanf(s+lll-1, "%s", s11);
            s11[rrr-lll+1] = 0;
            data[i].s = s11;
            // printf("%s\n", data[i].s);
            // scanf("%s", data[i].s);
            ac.insert(data[i].s, i);
        }
        ac.getfail();
        ac.find(s);
        for (int i = 1; i <= q; i++) {
            // if (data[i].kind == 0)
            //     printf("%d\n", ac.times[data[i].index][0]);
            // else
            //     printf("%d\n", ac.times[data[i].index][1]);
            auto it = ac.ans[data[i].index].begin();
            int LLL = ac.ans[data[i].index].size();
            if(LLL < qq[i]) printf("-1\n");
            else {
                printf("%d\n", *(it+qq[i]-1)+1-llen[i]);
            }
            // for(; it != ac.ans[data[i].index].end(); it++) {
            //     cout << *it << endl;
            // }
        }
    }
    return 0;
}
