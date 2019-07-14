#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4+5;
string maze[MAXN];
int row[MAXN], col[MAXN];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> maze[i];
        }
        int mm, nn;
        mm = nn = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(maze[i][j] == '.') {
                    row[i]++;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(maze[j][i] == '.') {
                    col[i]++;
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(maze[i][j] == '.') {
                    ans = min(ans, row[i]+col[j]-1);
                } else {
                    ans = min(ans, row[i]+col[j]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}