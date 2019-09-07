#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 3e5 + 100;
int n;
char s[MAXN];
struct S_AT {
    int ch[MAXN][27], fail[MAXN], len[MAXN], siz[MAXN], tot, lst;
    bool vis[MAXN][27];
    int num[MAXN];
    void init() {
        tot = 1;
        fail[0] = fail[1] = 1;
        len[1] = -1;
        memset(vis, 0, sizeof(vis));
        memset(num, 0, sizeof(num));
    }
    void add(int c, int n) {
        int p = lst;
        while (s[n - len[p] - 1] != s[n])
            p = fail[p];
        if (!ch[p][c]) {
            int now = ++tot, k = fail[p];
            for (int i = 0; i < 27; i++) {
                vis[now][i] = vis[p][i];
            }
            if (vis[now][c] == 0) {
                vis[now][c] = 1;
                num[now] = num[p] + 1;
            } else {
                num[now] = num[p];
            }
            len[now] = len[p] + 2;
            //cout<<len[now]<<endl;
            while (s[n - len[k] - 1] != s[n])
                k = fail[k];
            fail[now] = ch[k][c];
            ch[p][c] = now;
        }
        lst = ch[p][c];
        siz[lst]++;
    }
    LL solve() {
        LL A = 0;
        for (int i = tot; i; i--) {
            siz[fail[i]] += siz[i];
            A += siz[i] * num[i];
            //cout << siz[i] << " " << len[i] <<" "<<num[i]<< "\n";
            //ans = std::max(ans, 1ll * siz[i] * len[i]);
        }
        return A;
    }
} zkx;

int main() {
    //freopen("C:/Users/26254/Documentsxking/in.txt", "r", stdin);
    //freopen("C:/Users/26254/Documentsxking/out.txt", "w", stdout);

    scanf("%s", s + 1);
    zkx.init();
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        zkx.add(s[i] - 'a' + 1, i);
    }
    LL ans = zkx.solve();
    printf("%lld", ans);

    return 0;
}
